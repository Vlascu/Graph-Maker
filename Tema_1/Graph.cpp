#include "Graph.h"
#include <vector>

Graph::Graph()
{

}

std::vector<Node> Graph::getNodes()
{
    return m_nodes;
}

std::vector<Arch> Graph::getArches()
{
    return m_arches;
}

void Graph::addNode(QPoint p)
{
    m_nodes.push_back(Node(p, m_nodes.size() + 1));
}

void Graph::addArch(Node n1, Node n2)
{
    m_arches.push_back(Arch(n1, n2));
}

void Graph::addArch(Arch a)
{
    m_arches.push_back(a);
}

std::vector<Arch> Graph::getArches() const
{
    return m_arches;
}
