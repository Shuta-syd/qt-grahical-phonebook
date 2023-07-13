#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include <contact.h>
#include <QMap>
#include <QDebug>

class ContactList
{
public:
    ContactList();

public slots:
    void add(Contact &);
    void search();
    void remove();

private:
    QMap<QString, Contact> _contacts;
};

#endif // CONTACTLIST_H
