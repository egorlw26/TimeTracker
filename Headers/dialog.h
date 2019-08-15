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
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public:
    QString name() const;


private:
    Ui::Dialog* mp_ui;
};

#endif // DIALOG_H
