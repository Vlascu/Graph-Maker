#pragma once
#include "Arch.h"
#include <vector>
#include "Node.h"
#include <QPoint>
class Graph
{
public:
	Graph();
	std::vector<Node> getNodes();
	std::vector<Arch> getArches();
	void addNode(QPoint p);
	void addArch(Node n1, Node n2);
	void addArch(Arch a);
	std::vector<Arch> getArches() const;
private:
	std::vector<Node> m_nodes;
	std::vector<Arch>m_arches;
};

