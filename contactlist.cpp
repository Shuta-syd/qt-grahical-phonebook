#include "contactlist.h"

ContactList::ContactList() {}

void ContactList::add(Contact &contact) {
    // debug
    qDebug() << "This is ContactList::add()";

    this->_contacts.insert(contact.getPhoneNumber(), contact);

    // save contact to a file
    QFile file("temp");
    if (!file.open(QIODevice::WriteOnly)) {}

    QDataStream out(&file);

    for (auto it = this->_contacts.begin(); it != this->_contacts.end(); it++) {
        out << it->getName() << it->getPhoneNumber() << it->getEmailAddress();
    }
    file.close();
}

void ContactList::search() {}

void ContactList::remove() {}
