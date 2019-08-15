#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <string>
#include "activity.h"
#include "mainwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr, MainWindow* main_window = nullptr);
    ~Dialog();

signals:
    void AddNewActivity(QString i_name);

private slots:
    void on_CancelButton_clicked();
    void on_OkButton_clicked();

private:
    Ui::Dialog* mp_ui;
    MainWindow* mp_mw;
};

#endif // DIALOG_H
