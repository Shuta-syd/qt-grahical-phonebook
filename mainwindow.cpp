#include "mainwindow.h"
#include "removewindow.h"
#include "ui_mainwindow.h"
#include "searchwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), _addWin(new addWindow(this)), _searchWin(new searchWindow(this, this->_phoneBook)), _removeWin(new removeWindow(this))
{
    ui->setupUi(this);
    connect(_addWin, &addWindow::addContactSignal, this, &MainWindow::on_contact_added);
    connect(_removeWin, &removeWindow::requestDeleteContactSignal, this, &MainWindow::on_delete_contact);
    connect(_removeWin, &removeWindow::request_showup_contanct_byName, this, &MainWindow::on_showup_contanct_byName);
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
        _searchWin->exec();
}


void MainWindow::on_btnRemove_clicked() {
    // list up all of contact on tableWidget
    this->_removeWin->on_showup_contacts(this->_phoneBook.getContacts());

    _removeWin->exec();
}


void MainWindow::on_btnExit_clicked()
{
  close();
}

void MainWindow::on_contact_added(Contact &contact) {
   this->_phoneBook.add(contact);
}

void MainWindow::on_delete_contact(QString key) {
   this->_phoneBook.remove(key);
};

void MainWindow::on_showup_contanct_byName(QString &str) {
   this->_removeWin->showup_contacts_byName(str, this->_phoneBook.getContacts());
};
