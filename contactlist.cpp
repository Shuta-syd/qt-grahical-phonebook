#include "contactlist.h"

ContactList::ContactList() {}

QMap<QString, Contact> &ContactList::getContacts() { return this->_contacts; }

void ContactList::add(Contact &contact) {
    // debug
    qDebug() << "This is ContactList::add()";

    this->_contacts.insert(contact.getPhoneNumber(), contact);
    this->saveContacts();
}

void ContactList::search() {}

void ContactList::remove(QString key) {
    auto it = this->_contacts.find(key);
    qDebug() << key; // debug
    this->_contacts.remove(key);

    QMessageBox successMsg;
    successMsg.setText("Successfully delete a contact");
    successMsg.exec();
}

void ContactList::saveContacts() {
    // save contact to a file
    QString filePath = QDir::homePath() + "/contact_data.bin";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        // error message;
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
        // error message;
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
