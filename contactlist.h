#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <contact.h>
#include <QMap>

class ContactList
{
public:
    ContactList();
    void add();
    void search();
    void remove();

private:
    QMap<QString, Contact> _contacts;
};

#endif // CONTACTLIST_H
