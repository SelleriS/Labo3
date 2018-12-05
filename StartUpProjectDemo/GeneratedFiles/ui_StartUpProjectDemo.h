/********************************************************************************
** Form generated from reading UI file 'StartUpProjectDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUPPROJECTDEMO_H
#define UI_STARTUPPROJECTDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartUpProjectDemoClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StartUpProjectDemoClass)
    {
        if (StartUpProjectDemoClass->objectName().isEmpty())
            StartUpProjectDemoClass->setObjectName(QStringLiteral("StartUpProjectDemoClass"));
        StartUpProjectDemoClass->resize(600, 400);
        menuBar = new QMenuBar(StartUpProjectDemoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        StartUpProjectDemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(StartUpProjectDemoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        StartUpProjectDemoClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(StartUpProjectDemoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        StartUpProjectDemoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(StartUpProjectDemoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        StartUpProjectDemoClass->setStatusBar(statusBar);

        retranslateUi(StartUpProjectDemoClass);

        QMetaObject::connectSlotsByName(StartUpProjectDemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *StartUpProjectDemoClass)
    {
        StartUpProjectDemoClass->setWindowTitle(QApplication::translate("StartUpProjectDemoClass", "StartUpProjectDemo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartUpProjectDemoClass: public Ui_StartUpProjectDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUPPROJECTDEMO_H
