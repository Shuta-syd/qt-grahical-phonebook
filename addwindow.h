#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include <contact.h>

namespace Ui {
class addWindow;
}

class addWindow : public QDialog
{
    Q_OBJECT

public:
    explicit addWindow(QWidget *parent = nullptr);
    ~addWindow();

private slots:
    void on_pushButton_clicked();
signals:
    void addContactSignal(Contact &);

private:
    Ui::addWindow *ui;
};

#endif // ADDWINDOW_H
