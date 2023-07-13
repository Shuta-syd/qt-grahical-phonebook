#include "contact.h"

Contact::Contact() {}

QString &Contact::getName() { return this->_name; }
QString &Contact::getPhoneNumber() { return this->_phoneNumber; }
QString &Contact::getEmailAddress() { return this->_emailAddress; }

void Contact::setName(QString name) { this->_name = name; }
void Contact::setPhoneNumber(QString phoneNumber) { this->_phoneNumber = phoneNumber; }
void Contact::setEmailAddress(QString emailAddress) { this->_emailAddress = emailAddress; }
