#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searchwindow.h"
#include "removewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), _addWin(new addWindow(this))
{
    ui->setupUi(this);
    connect(_addWin, &addWindow::addContactSignal, this, &MainWindow::on_contact_added);
    this->_phoneBook.loadContacts();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete _addWin;
}


void MainWindow::on_btnAdd_clicked() { _addWin->exec(); }


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
  close();
}

void MainWindow::on_contact_added(Contact &contact) {
   this->_phoneBook.add(contact);
}
