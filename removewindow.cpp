#include "removewindow.h"
#include "ui_removewindow.h"

removeWindow::removeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeWindow)
{
    ui->setupUi(this);
}

removeWindow::~removeWindow() { delete ui; }

void removeWindow::on_showup_contacts(QMap<QString, Contact> contacts) {
    ui->tableWidget->setRowCount(contacts.size());

    int row = 0;
    for (auto it = contacts.begin(); it != contacts.end(); it++, row++) {
        qDebug() << it->getName();
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(it->getName()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(it->getPhoneNumber()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(it->getEmailAddress()));
    }
}

void removeWindow::showup_contacts_byName(QString& str, const QMap<QString, Contact>&contacts) {
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(contacts.size());

    int row = 0;
    int i = 0;
    for (auto it = contacts.begin(); it != contacts.end(); it++, row++) {
        if (it->getName().contains(str)) {
            row -= i;
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(it->getName()));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(it->getPhoneNumber()));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(it->getEmailAddress()));
            i = 0;
            continue;
        }
        i++;
    }
}

void removeWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    // pop-up a window to check yes or no
    QTableWidgetItem* item = ui->tableWidget->item(row, 1);
    QMessageBox msgBox;
    msgBox.setInformativeText("Do you want to delete this contact?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int ret = msgBox.exec();

    if (ret == 1024) {
      emit requestDeleteContactSignal(item->text());
      this->close();
    }
}

void removeWindow::on_removeInput_returnPressed() {
    QString str = ui->removeInput->text();
    emit request_showup_contanct_byName(str);
}

