#ifndef REMOVEWINDOW_H
#define REMOVEWINDOW_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QDebug>
#include <QMap>
#include <QString>
#include "contact.h"

namespace Ui {
class removeWindow;
}

class removeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit removeWindow(QWidget *parent = nullptr);
    ~removeWindow();
    void on_showup_contacts(QMap<QString, Contact> contacts);

private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);

signals:
    void requestDeleteContactSignal(int);

private:
    Ui::removeWindow *ui;
};

#endif // REMOVEWINDOW_H
