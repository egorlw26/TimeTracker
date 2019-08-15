#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    mp_ui(new Ui::Dialog)
{
    mp_ui->setupUi(this);
    connect(mp_ui->OkButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(mp_ui->CancelButton, &QAbstractButton::clicked, this, &QDialog::reject);
}

Dialog::~Dialog()
{
    delete mp_ui;
}

QString Dialog::name() const
{
    return mp_ui->InputLine->text();
}

