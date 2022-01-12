#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ClassTable.h"

class ClassTable : public QMainWindow
{
    Q_OBJECT

public:
    ClassTable(QWidget *parent = Q_NULLPTR);

private:
    Ui::ClassTableClass ui;
};
