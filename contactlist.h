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
    void remove(QString);

    void saveContacts();
    void loadContacts();
    void recreateContacts();

    const QMap<QString, Contact>& getContacts() const;

private:
    QMap<QString, Contact> _contacts;
};

#endif // CONTACTLIST_H
