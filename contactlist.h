#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "contact.h"
#include <QMap>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QString>

class ContactList
{
public:
    ContactList();

    void add(Contact &);
    void search();
    void remove();
    const QMap<QString, Contact>& getContacts() const;
    void loadContacts();

private:
    QMap<QString, Contact> _contacts;
};

#endif // CONTACTLIST_H
