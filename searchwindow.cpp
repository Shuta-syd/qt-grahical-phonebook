#include "searchwindow.h"
#include "ui_searchwindow.h"
#include <QMessageBox>

searchWindow::searchWindow(QWidget *parent, const ContactList& phoneBook) :
    QDialog(parent),
    ui(new Ui::searchWindow),
    _contacts(phoneBook.getContacts())
{
    ui->setupUi(this);

    // add every contacts to QListWidget
    for (auto it = _contacts.constBegin(); it != _contacts.constEnd(); ++it) {
        QString listItemText = it.value().getName();
        ui->listWidget->addItem(listItemText);
    }
}

searchWindow::~searchWindow()
{
    delete ui;
}

void searchWindow::on_pushButton_clicked()
{
    QString searchInput = ui->searchInput->text();
    _searchResults.clear();

    for (auto it = _contacts.begin(); it != _contacts.end(); ++it) {
        if (it->getName().contains(searchInput, Qt::CaseInsensitive)) {
            _searchResults.append(*it);
        }
    }

    ui->listWidget->clear();
    for (const auto& contact : _searchResults) {
        QString listItemText = contact.getName();
        ui->listWidget->addItem(listItemText);
    }
}

void searchWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int selectedIndex = ui->listWidget->row(item);

    if (selectedIndex >= 0 && selectedIndex < _searchResults.size()) {
        const Contact& selectedContact = _searchResults.at(selectedIndex);

        QString message = "name: " + selectedContact.getName() + "\n"
                          "phone number: " + selectedContact.getPhoneNumber() + "\n"
                              "email address: " + selectedContact.getEmailAddress();

                                                             QMessageBox::about(this, "detail of contacts", message);
    }
}

