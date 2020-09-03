/********************************************************************************
** Form generated from reading UI file 'TCPClient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCPClientClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TCPClientClass)
    {
        if (TCPClientClass->objectName().isEmpty())
            TCPClientClass->setObjectName(QStringLiteral("TCPClientClass"));
        TCPClientClass->resize(600, 400);
        centralWidget = new QWidget(TCPClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 70, 75, 23));
        TCPClientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TCPClientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        TCPClientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TCPClientClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TCPClientClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TCPClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TCPClientClass->setStatusBar(statusBar);

        retranslateUi(TCPClientClass);

        QMetaObject::connectSlotsByName(TCPClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *TCPClientClass)
    {
        TCPClientClass->setWindowTitle(QApplication::translate("TCPClientClass", "TCPClient", Q_NULLPTR));
        pushButton->setText(QApplication::translate("TCPClientClass", "send", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TCPClientClass: public Ui_TCPClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
