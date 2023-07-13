#include "removewindow.h"
#include "ui_removewindow.h"

removeWindow::removeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeWindow)
{
    ui->setupUi(this);
}

removeWindow::~removeWindow()
{
    delete ui;
}
