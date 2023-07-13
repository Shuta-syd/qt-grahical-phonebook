#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>

namespace Ui {
class addWindow;
}

class addWindow : public QDialog
{
    Q_OBJECT

public:
    explicit addWindow(QWidget *parent = nullptr);
    ~addWindow();

private:
    Ui::addWindow *ui;
};

#endif // ADDWINDOW_H
