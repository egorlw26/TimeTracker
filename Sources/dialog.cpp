#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    mp_ui(new Ui::Dialog)
{
    mp_ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete mp_ui;
}


void Dialog::on_CancelButton_clicked()
{
    Dialog::close();
}

void Dialog::on_OkButton_clicked()
{
    if(mp_ui->InputLine->text() != "")
    {
        QString actName = mp_ui->InputLine->text();
        (*mp_mw).getTracker().addActivity(Activity(actName));
        Dialog::close();
    }
}

