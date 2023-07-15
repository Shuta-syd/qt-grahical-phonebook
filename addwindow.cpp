#include "addwindow.h"
#include "ui_addwindow.h"
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>
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

#include <QRegularExpression>

// ...

void addWindow::on_addContactBtn_clicked()
{
    QString name = ui->nameInput->text().trimmed();
    QString phoneNumber = ui->phoneNumberInput->text().trimmed();
    QString emailAddress = ui->emailInput->text().trimmed();

    bool hasError = false;
    QString errorMessage;

    // Check for empty fields
    if (name.isEmpty() || phoneNumber.isEmpty() || emailAddress.isEmpty()) {
        hasError = true;
        errorMessage = "Error: One or more fields are empty.";
    }

    // Check phone number format
    QRegularExpression phoneRegex("^\\d{10}$"); // Assuming phone number format is 10 digits
    if (!phoneRegex.match(phoneNumber).hasMatch()) {
        hasError = true;
        errorMessage = "Error: Invalid phone number format.";
    }

    // Check email format
    QRegularExpression emailRegex("^\\S+@\\S+\\.\\S+$");
    if (!emailRegex.match(emailAddress).hasMatch()) {
        hasError = true;
        errorMessage = "Error: Invalid email format.";
    }

    if (hasError) {
        // Display the error message in a QMessageBox
        QMessageBox::critical(this, "Error", errorMessage);
        return; // Exit the function to prevent further execution
    }


    // No errors, proceed with creating and emitting the signal
    Contact contact;
    contact.setName(name);
    contact.setPhoneNumber(phoneNumber);
    contact.setEmailAddress(emailAddress);

    // Debug
    qDebug() << contact.getName() << contact.getPhoneNumber() << contact.getEmailAddress();

    // Signal and slot
    emit addContactSignal(contact);
    QMessageBox::information(this, "Success", "Contact added successfully!");

    close();
    ui->nameInput->clear();
    ui->phoneNumberInput->clear();
    ui->emailInput->clear();
}




