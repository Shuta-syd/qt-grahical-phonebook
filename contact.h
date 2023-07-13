#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact
{
public:
    Contact();

    // getter setter
    QString &getName();
    QString &getPhoneNumber();
    QString &getEmailAddress();

    void setName(QString);
    void setPhoneNumber(QString);
    void setEmailAddress(QString);

private:
    QString _name;
    QString _phoneNumber;
    QString _emailAddress;
};

#endif // CONTACT_H
