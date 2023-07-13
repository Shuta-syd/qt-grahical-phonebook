#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addwindow.h"
#include "searchwindow.h"
#include "removewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAdd_clicked()
{
    addWindow *addWin = new addWindow(this);

    addWin->exec();
}


void MainWindow::on_btnSearch_clicked()
{
    searchWindow *searchWin = new searchWindow(this);

    searchWin->exec();
}


void MainWindow::on_btnRemove_clicked()
{
    removeWindow *removeWin = new removeWindow(this);

    removeWin->exec();
}


void MainWindow::on_btnExit_clicked()
{

}

