#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QDialog>

namespace Ui {
class searchWindow;
}

class searchWindow : public QDialog
{
    Q_OBJECT

public:
    explicit searchWindow(QWidget *parent = nullptr);
    ~searchWindow();

private:
    Ui::searchWindow *ui;
};

#endif // SEARCHWINDOW_H
