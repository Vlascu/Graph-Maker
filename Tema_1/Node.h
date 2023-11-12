#pragma once
#include <QPoint>
class Node
{
public:
	Node();
	Node(QPoint p, int value=-1):m_pos(p),m_value(value){}
	void setValue(int val);
	void setPosition(QPoint p);
	int getValue();
	int getX();
	int getY();
	QPoint getPosition();



private:
	int m_value = { -1 };
	QPoint m_pos;
};

