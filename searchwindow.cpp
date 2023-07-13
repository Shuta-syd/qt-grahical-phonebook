#include "searchwindow.h"
#include "ui_searchwindow.h"

searchWindow::searchWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchWindow)
{
    ui->setupUi(this);
}

searchWindow::~searchWindow()
{
    delete ui;
}
