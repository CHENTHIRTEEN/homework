/********************************************************************************
** Form generated from reading UI file 'ClassTable.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSTABLE_H
#define UI_CLASSTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassTableClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ClassTableClass)
    {
        if (ClassTableClass->objectName().isEmpty())
            ClassTableClass->setObjectName(QString::fromUtf8("ClassTableClass"));
        ClassTableClass->resize(600, 400);
        menuBar = new QMenuBar(ClassTableClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ClassTableClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ClassTableClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ClassTableClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ClassTableClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ClassTableClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ClassTableClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ClassTableClass->setStatusBar(statusBar);

        retranslateUi(ClassTableClass);

        QMetaObject::connectSlotsByName(ClassTableClass);
    } // setupUi

    void retranslateUi(QMainWindow *ClassTableClass)
    {
        ClassTableClass->setWindowTitle(QApplication::translate("ClassTableClass", "ClassTable", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClassTableClass: public Ui_ClassTableClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSTABLE_H
