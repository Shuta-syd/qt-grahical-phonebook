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
#include <QMessageBox>

class ContactList
{
public:
    ContactList();

    void add(Contact &);
    void search();
    void remove(int);

    void saveContacts();
    void loadContacts();
    QMap<QString, Contact> &getContacts();

private:
    QMap<QString, Contact> _contacts;
};

#endif // CONTACTLIST_H
