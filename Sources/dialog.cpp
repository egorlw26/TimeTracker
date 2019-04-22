#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_CancelButton_clicked()
{
    Dialog::close();
}

void Dialog::on_OkButton_clicked()
{
    if(ui->InputLine->text() != "")
    {
        QString actName = ui->InputLine->text();
        std::string aName = actName.toLocal8Bit().constData();
        (*mw).getTracker().addActivity(Activity(aName));
        Dialog::close();
    }
}
