/********************************************************************************
** Form generated from reading UI file 'Tema_1.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMA_1_H
#define UI_TEMA_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tema_1Class
{
public:
    QWidget *centralWidget;
    QRadioButton *radioButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tema_1Class)
    {
        if (Tema_1Class->objectName().isEmpty())
            Tema_1Class->setObjectName("Tema_1Class");
        Tema_1Class->resize(600, 400);
        centralWidget = new QWidget(Tema_1Class);
        centralWidget->setObjectName("centralWidget");
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(470, 20, 89, 20));
        Tema_1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Tema_1Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        Tema_1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tema_1Class);
        mainToolBar->setObjectName("mainToolBar");
        Tema_1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Tema_1Class);
        statusBar->setObjectName("statusBar");
        Tema_1Class->setStatusBar(statusBar);

        retranslateUi(Tema_1Class);

        QMetaObject::connectSlotsByName(Tema_1Class);
    } // setupUi

    void retranslateUi(QMainWindow *Tema_1Class)
    {
        Tema_1Class->setWindowTitle(QCoreApplication::translate("Tema_1Class", "Tema_1", nullptr));
        radioButton->setText(QCoreApplication::translate("Tema_1Class", "Graf orientat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tema_1Class: public Ui_Tema_1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMA_1_H
