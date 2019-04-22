#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "fstream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Tick()));
    timer->start(100);
    needToRefreshNames = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Tick()
{
            if(needToRefreshNames)
                ui->ListNames->clear();
            ui->ListTimes->clear();
            for(size_t i = 0; i<tracker.getActivities().size(); ++i)
            {
                if(needToRefreshNames)
                    ui->ListNames->addItem(tracker.getActivities()[i].getQStringName());
                tracker.getActivities()[i].update();
                int time = (int)tracker.getActivities()[i].getDuration();
                int hours, minutes, seconds;
                hours = time/3600;
                minutes = (time - hours*3600)/60;
                seconds = time - hours*3600 - minutes*60;
                std::string info = std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
                ui->ListTimes->addItem(QString::fromStdString(info));
            }
            needToRefreshNames = false;
}

void MainWindow::on_AddButton_clicked()
{
    Dialog d;
    d.setMainWindow(this);
    d.exec();
    needToRefreshNames = true;
}

void MainWindow::on_StopButton_clicked()
{
     for(size_t i = 0; i<tracker.getActivities().size(); ++i)
     {
        if(ui->ListNames->item(i)->isSelected())
        {
            tracker.getActivities()[i].setStatus(0);
        }
     }
}

void MainWindow::on_StartButton_clicked()
{
    for(size_t i = 0; i<tracker.getActivities().size(); ++i)
    {
        if(ui->ListNames->item(i)->isSelected())
        {
            tracker.getActivities()[i].setStatus(1);
            tracker.getActivities()[i].setStartNow();
        }
    }
}

void MainWindow::on_Finish_Button_clicked()
{

    for(size_t i = 0; i<tracker.getActivities().size(); ++i)
    {
        if(ui->ListNames->item(i)->isSelected())
        {
            tracker.getActivities()[i].setStatus(-1);
        }
    }
}

void MainWindow::on_RemoveButton_clicked()
{
    for (size_t i=0; i<tracker.getActivities().size(); ++i)
    {
        if(ui->ListNames->item(i)->isSelected())
        {
            tracker.getActivities().erase(tracker.getActivities().begin() + i);
        }
    }
    needToRefreshNames = true;
}

void MainWindow::on_actionSave_triggered()
{
    std::ofstream out("Log.txt");
    if(out.is_open())
    {
        out<<tracker.getActivities().size()<<'\n';
        for(size_t i = 0 ; i<tracker.getActivities().size(); ++i)
            out<<tracker.getActivities()[i].getName()<<' '<<tracker.getActivities()[i].getDuration()<<'\n';
    }
}

void MainWindow::on_actionLoad_triggered()
{
    std::ifstream in("Log.txt");
    if(in.is_open())
    {
        std::string line;
        std::getline(in, line);
        int size = std::stoi(line);
        for(size_t i = 0; i<size; ++i)
        {
            std::string name;
            double dur;
            in>>name;
            in>>line;
            dur = std::stod(line);
            tracker.addActivity(Activity(name, dur));
        }
        needToRefreshNames = true;
    }
}
