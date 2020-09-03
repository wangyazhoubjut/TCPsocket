/********************************************************************************
** Form generated from reading UI file 'showData.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWDATA_H
#define UI_SHOWDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showDataClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *showDataClass)
    {
        if (showDataClass->objectName().isEmpty())
            showDataClass->setObjectName(QStringLiteral("showDataClass"));
        showDataClass->resize(600, 400);
        centralWidget = new QWidget(showDataClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 60, 211, 121));
        showDataClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(showDataClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        showDataClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(showDataClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        showDataClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(showDataClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        showDataClass->setStatusBar(statusBar);

        retranslateUi(showDataClass);

        QMetaObject::connectSlotsByName(showDataClass);
    } // setupUi

    void retranslateUi(QMainWindow *showDataClass)
    {
        showDataClass->setWindowTitle(QApplication::translate("showDataClass", "showData", Q_NULLPTR));
        label->setText(QApplication::translate("showDataClass", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class showDataClass: public Ui_showDataClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWDATA_H
