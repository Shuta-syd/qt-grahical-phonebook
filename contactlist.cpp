#include "contactlist.h"

ContactList::ContactList() {}

void ContactList::add(Contact &contact) {
    //this->_contacts.insert()
    qDebug() << "signal and slot" << contact.getName();
}

void ContactList::search() {}

void ContactList::remove() {}
