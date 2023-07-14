#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QString>
#include "contactlist.h"
#include "addwindow.h"
#include "removewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addContact();

private slots:
    void on_btnAdd_clicked();
    void on_btnSearch_clicked();
    void on_btnRemove_clicked();
    void on_btnExit_clicked();

    void on_contact_added(Contact &);
    void on_delete_contact(QString);

private:
    Ui::MainWindow *ui;
    ContactList _phoneBook;
    addWindow *_addWin;
    removeWindow *_removeWin;
};
#endif // MAINWINDOW_H
