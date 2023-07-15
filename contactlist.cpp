#include "contactlist.h"

ContactList::ContactList() {}

QMap<QString, Contact> &ContactList::getContacts() { return this->_contacts; }

void ContactList::add(Contact &contact) {
    this->_contacts.insert(contact.getPhoneNumber(), contact);
    this->saveContacts();
}

void ContactList::search() {}

void ContactList::remove(QString key) {
    this->_contacts.find(key);
    this->_contacts.remove(key);

    QMessageBox successMsg;
    successMsg.setText("Successfully delete a contact");
    successMsg.exec();

    // delete contact from binary file
    this->recreateContacts();
}

void ContactList::saveContacts() {
    // save contact to a file

    QString filePath = QDir::homePath() + "/contact_data.bin";
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox msgbox;
        msgbox.critical(nullptr, "Error", ": to open file failed");
        return;
    }

    QDataStream out(&file);

    for (auto it = this->_contacts.begin(); it != this->_contacts.end(); it++) {
        out << it->getName() << it->getPhoneNumber() << it->getEmailAddress();
    }

    file.flush();
    file.close();
}

void ContactList::loadContacts() {
    QFile file(QDir::homePath() + "/contact_data.bin");

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox msgbox;
        msgbox.critical(nullptr, "Error", ": to open file failed");
        return;
    }

    QDataStream in(&file);

    while (!in.atEnd()) {
        QString name;
        QString phoneNumber;
        QString emailAddress;

        in >> name >> phoneNumber >> emailAddress;

        Contact contact(name, phoneNumber, emailAddress);
        this->_contacts.insert(phoneNumber, contact);
    }

    file.close();

    for (auto it = this->_contacts.begin(); it != this->_contacts.end(); it++) {
        qDebug() << it->getName() << it->getPhoneNumber() << it->getEmailAddress();
    }
}

void ContactList::recreateContacts() {
    QString filePath = QDir::homePath() + "/contact_data.bin";
    QFile file(filePath);

    // delete a file
    if (!file.remove()) {
        QMessageBox msgbox;
        msgbox.critical(nullptr, "Error", ": to remove file failed");
        return;
    }

    this->saveContacts();
}
