// searchwindow.h

#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QListWidgetItem>
#include <QDialog>
#include <QMap>
#include "contactlist.h"

namespace Ui {
class searchWindow;
}

class searchWindow : public QDialog
{
    Q_OBJECT

public:
    explicit searchWindow(QWidget *parent = nullptr, const ContactList& phoneBook = {});

    ~searchWindow();

private slots:
    void on_pushButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::searchWindow *ui;
    const QMap<QString, Contact>& _contacts;
    QList<Contact> _searchResults;
    ContactList _phoneBook;
};

#endif // SEARCHWINDOW_H
