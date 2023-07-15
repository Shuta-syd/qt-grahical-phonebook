#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "contactlist.h"
#include "addwindow.h"
#include "searchwindow.h"

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

private:
    Ui::MainWindow *ui;
    ContactList _phoneBook;
    addWindow *_addWin;
    searchWindow * _searchWin;

};
#endif // MAINWINDOW_H
