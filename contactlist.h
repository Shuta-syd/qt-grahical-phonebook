#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "contact.h"
#include <QMap>
#include <QDebug>
#include <QFile>
#include <QString>
#include <QDir>
#include <QDataStream>
#include <QStandardPaths>

class ContactList
{
public:
    ContactList();

    void add(Contact &);
    void search();
    void remove();

    void saveContacts();
    void loadContacts();
  
    const QMap<QString, Contact>& getContacts() const;

private:
    QMap<QString, Contact> _contacts;
};

#endif // CONTACTLIST_H
