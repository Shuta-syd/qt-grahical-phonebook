#include "addwindow.h"
#include "ui_addwindow.h"
#include <QDebug>
addWindow::addWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addWindow)
{
    ui->setupUi(this);
}

addWindow::~addWindow()
{
    delete ui;
}

void addWindow::on_addContactBtn_clicked()
{
    Contact contact;
    QString name = ui->nameInput->text();
    QString phoneNumber = ui->phoneNumberInput->text();
    QString emailAddress = ui->emailInput->text();

    // handle error case (empty, all spaces)

    contact.setName(name);
    contact.setPhoneNumber(phoneNumber);
    contact.setEmailAddress(emailAddress);

    // debug
    qDebug() << contact.getName() << contact.getPhoneNumber() << contact.getEmailAddress();

    if (1) {
        emit this->addContactSignal(contact);
        ui->label_add->setText("Added successfully");
    } else {
        ui->label_add->setText("Failed");
    }
    // signal and slot

}

