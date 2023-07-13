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

void addWindow::on_pushButton_clicked()
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

    // signal and slot
    emit this->addContactSignal(contact);
}

