#pragma once
#include "Node.h"
class Arch
{
public:
	Arch() {};
	Arch(Node n1, Node n2) : m_firstNode(n1), m_secondNode(n2) {};
	Node getFirstNode();
	Node getSecondNode();
private:
	Node m_firstNode, m_secondNode;
};

