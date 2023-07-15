// contact.h

#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact
{
public:
    Contact();
    Contact(QString name, QString phoneNumber, QString emailAddress);

    QString getName() const; // const 키워드 추가
    QString getPhoneNumber() const; // const 키워드 추가
    QString getEmailAddress() const; // const 키워드 추가

    void setName(QString name);
    void setPhoneNumber(QString phoneNumber);
    void setEmailAddress(QString emailAddress);

private:
    QString _name;
    QString _phoneNumber;
    QString _emailAddress;
};

#endif // CONTACT_H
