#include "Node.h"

Node::Node()
{
}

void Node::setValue(int val)
{
	m_value = val;
}
void Node::setPosition(QPoint p)
{
	m_pos = p;
}

int Node::getValue()
{
	return m_value;
}
int Node::getX()
{
	return m_pos.x();
}
int Node::getY()
{
	return m_pos.y();
}
QPoint Node::getPosition()
{
	return m_pos;
}

