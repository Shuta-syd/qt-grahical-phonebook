#include "contactlist.h"

ContactList::ContactList() {}

void ContactList::add(Contact &contact) {
    // debug
    qDebug() << "This is ContactList::add()";
    qDebug() << QDir::homePath();

    this->_contacts.insert(contact.getPhoneNumber(), contact);

    // save contact to a file
    QString filePath = QDir::homePath() + "/contact_data.bin";
    qDebug() << filePath;
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

void ContactList::search() {}

void ContactList::remove() {}

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
