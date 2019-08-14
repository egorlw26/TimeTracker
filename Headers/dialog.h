#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "activity.h"
#include "mainwindow.h"
#include <string>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setMainWindow(MainWindow* ip_mw) {this->mp_mw = ip_mw;}

private slots:
    void on_CancelButton_clicked();
    void on_OkButton_clicked();

private:
    Ui::Dialog* mp_ui;
    MainWindow* mp_mw;
};

#endif // DIALOG_H
