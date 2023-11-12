#pragma once

#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QRect>
#include <QPen>
#include <QPainter>
#include "ui_Tema_1.h"
#include "Graph.h"
#include "Node.h"

class Tema_1 : public QMainWindow
{
    Q_OBJECT

public:
    Tema_1(QWidget *parent = nullptr);
    ~Tema_1();
	virtual void mouseReleaseEvent(QMouseEvent* e);
    virtual void paintEvent(QPaintEvent* e);
private slots:
    void onRadioButtonOriented();
private:
    Ui::Tema_1Class ui;
    Graph m_graph;
    Node m_firstNode;
    std::vector<std::vector<uint16_t>> m_adjacencyMatrix;
    bool m_isOriented;
    bool nodeOverlaps(const QPoint&);
    bool checkArchExists(const std::vector<Arch>&, Node&, Node&);
    void setAdjacenciesValues(int position1, int position2);
    void exportAdjacencyMatrix();
};
