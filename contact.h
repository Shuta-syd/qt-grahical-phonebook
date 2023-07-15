// contact.h

#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact
{
public:
    Contact();
    Contact(QString name, QString phoneNumber, QString emailAddress);

    QString getName() const; // add const keyword
    QString getPhoneNumber() const; // add const keyword
    QString getEmailAddress() const; // add const keyword

    void setName(QString name);
    void setPhoneNumber(QString phoneNumber);
    void setEmailAddress(QString emailAddress);

private:
    QString _name;
    QString _phoneNumber;
    QString _emailAddress;
};

#endif // CONTACT_H
