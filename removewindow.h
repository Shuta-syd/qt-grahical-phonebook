#ifndef REMOVEWINDOW_H
#define REMOVEWINDOW_H

#include <QDialog>

namespace Ui {
class removeWindow;
}

class removeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit removeWindow(QWidget *parent = nullptr);
    ~removeWindow();

private:
    Ui::removeWindow *ui;
};

#endif // REMOVEWINDOW_H
