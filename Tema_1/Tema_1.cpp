#include "Tema_1.h"
#include <fstream>

Tema_1::Tema_1(QWidget *parent)
    : QMainWindow(parent)
{
    m_isOriented = false;
    ui.setupUi(this);
	connect(ui.radioButton, &QRadioButton::clicked, this, &Tema_1::onRadioButtonOriented);
}

Tema_1::~Tema_1()
{}

void Tema_1::mouseReleaseEvent(QMouseEvent* e)
{
	if (e->button() == Qt::RightButton)
	{
		if (!nodeOverlaps(e->pos())) {
			m_graph.addNode(e->pos());

			const int newNodeIndex = m_graph.getNodes().size();
			for (auto& row : m_adjacencyMatrix) {
				row.push_back(0);
			}
			m_adjacencyMatrix.push_back(std::vector<uint16_t>(newNodeIndex, 0));

			update();
		}
	}
	else if (e->button() == Qt::LeftButton)
	{
		std::vector<Node> nodes = m_graph.getNodes();

		for (Node& node : nodes)
		{
			if (fabs(node.getX() - e->pos().x()) < 10 && fabs(node.getY() - e->pos().y()) < 10)
			{
				if (m_firstNode.getValue() == -1)
				{
					m_firstNode = node;
				}
				else
				{
					if (!checkArchExists(m_graph.getArches(), m_firstNode, node))
					{
						m_graph.addArch(m_firstNode, node);
						setAdjacenciesValues(m_firstNode.getValue(), node.getValue());
						exportAdjacencyMatrix();
						m_firstNode.setValue(-1);
					}
				}
				update();
				break;
			}
		}
	}
}

void Tema_1::paintEvent(QPaintEvent* e)
{
	QPainter p(this); 

	std::vector<Node> nodes = m_graph.getNodes();

	for (Node& node : nodes)
	{
		QRect r(node.getX() - 10, node.getY() - 10, 20, 20); 

		p.drawEllipse(r);

		QString s;
		s.setNum(node.getValue());

		p.drawText(r, Qt::AlignCenter, s);
	}

	std::vector<Arch> arches = m_graph.getArches();

	for (Arch& arch : arches)
	{
		if(!m_isOriented)
			p.drawLine(arch.getFirstNode().getX(), arch.getFirstNode().getY(), arch.getSecondNode().getX(), arch.getSecondNode().getY());
		else
		{
			
			int lineStartX = arch.getFirstNode().getX();
			int lineStartY = arch.getFirstNode().getY();
			int lineEndX = arch.getSecondNode().getX();
			int lineEndY = arch.getSecondNode().getY();
			
			const qreal arrowSize = 15;
			p.setPen(Qt::black);
			p.setBrush(Qt::black);
		
			QLineF line(QPointF(lineEndX,lineEndY), QPointF(lineStartX,lineStartY));
			
			double angle = std::atan2(-line.dy(), line.dx());
			QPointF arrowP1 = line.p1() + QPointF(sin(angle + M_PI / 3) * arrowSize,
				cos(angle + M_PI / 3) * arrowSize);
			QPointF arrowP2 = line.p1() + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,
				cos(angle + M_PI - M_PI / 3) * arrowSize);

			QPolygonF arrowHead;
			arrowHead.clear();
			arrowHead << line.p1() << arrowP1 << arrowP2;
			p.drawLine(line);
			p.drawPolygon(arrowHead);
			p.setPen(Qt::NoPen);
			p.setBrush(Qt::NoBrush);
			
		}
	}

	if (m_firstNode.getValue() > 0)
	{
		QPen pen;

		pen.setColor(Qt::red);
		p.setPen(pen);

		QRect r(m_firstNode.getX() - 10, m_firstNode.getY() - 10, 20, 20);

		p.drawEllipse(r);

		QString s;
		s.setNum(m_firstNode.getValue());

		p.drawText(r, Qt::AlignCenter, s);
	}
}

void Tema_1::onRadioButtonOriented()
{
	if (ui.radioButton->isChecked())
	{
		m_isOriented = true;
		update();
	}
	else
		m_isOriented = false;

}

bool Tema_1::nodeOverlaps(const QPoint& insertedNode)
{
	std::vector<Node> nodes = m_graph.getNodes();
	const uint16_t combinedNodesRadius = 20;

	for (Node& n : nodes) {

		if (qSqrt(qPow(n.getX() - insertedNode.x(), 2) + qPow(n.getY() - insertedNode.y(), 2)) < combinedNodesRadius) {
			return true;
		}
	}
	return false;
}

bool Tema_1::checkArchExists(const std::vector<Arch>& arches, Node& firstNode, Node& secondNode)
{
	for (auto arch : arches)
	{
		if (arch.getFirstNode().getX() == firstNode.getX()
			&& arch.getFirstNode().getY() == firstNode.getY()
			&& arch.getSecondNode().getX() == secondNode.getX()
			&& arch.getSecondNode().getY() == secondNode.getY())
			return true;
	}
	return false;
}

void Tema_1::setAdjacenciesValues(int fromNodeValue, int toNodeValue)
{
	m_adjacencyMatrix.resize(m_graph.getNodes().size(), std::vector<uint16_t>(m_graph.getNodes().size(), 0));
	m_adjacencyMatrix[fromNodeValue-1][toNodeValue-1] = 1;
	m_adjacencyMatrix[toNodeValue-1][fromNodeValue-1] = 1;
}

void Tema_1::exportAdjacencyMatrix()
{
	std::ofstream output("adjancenyMatrix.txt");
	for (int index=0;index<m_graph.getNodes().size();index++)
	{
		output << index + 1 << " ";
	}
	output << std::endl;
	for (int index = 0; index < m_adjacencyMatrix.size(); index++)
	{
		for (int index2 = 0; index2 < m_adjacencyMatrix[index].size(); index2++)
			output << m_adjacencyMatrix[index][index2] << " ";
		output << std::endl;
	}
	output.close();
}

