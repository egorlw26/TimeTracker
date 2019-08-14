#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "fstream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mp_timer = new QTimer(this);
    connect(mp_timer, SIGNAL(timeout()), this, SLOT(Tick()));
//    connect(ui->AddButton, &QAbstractButton::clicked, this, &MainWindow::Create);
    mp_timer->start(50);
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
            for(int i = 0; i < m_tracker.getActivities().size(); ++i)
            {
                if(needToRefreshNames)
                    ui->ListNames->addItem(m_tracker.getActivities()[i].getName());
                m_tracker.getActivities()[i].update();
                int time = static_cast<int>(m_tracker.getActivities()[i].getDuration());
                int hours, minutes, seconds;
                hours = time/3600;
                minutes = (time - hours*3600)/60;
                seconds = time - hours*3600 - minutes*60;
                QString info = QString::number(hours) + ":" + QString::number(minutes) + ":" + QString::number(seconds);
                ui->ListTimes->addItem(info);
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
     for(int i = 0; i < m_tracker.getActivities().size(); ++i)
     {
        if(ui->ListNames->item(i)->isSelected())
        {
            m_tracker.getActivities()[i].setStatus(static_cast<int>(Activity::Status::Paused));
        }
     }
}

void MainWindow::on_StartButton_clicked()
{
    for(int i = 0; i<m_tracker.getActivities().size(); ++i)
    {
        if(ui->ListNames->item(i)->isSelected())
        {
            m_tracker.getActivities()[i].setStatus(static_cast<int>(Activity::Status::Started));
            m_tracker.getActivities()[i].setStartNow();
        }
    }
}

void MainWindow::on_Finish_Button_clicked()
{

    for(int i = 0; i<m_tracker.getActivities().size(); ++i)
    {
        if(ui->ListNames->item(i)->isSelected())
        {
            m_tracker.getActivities()[i].setStatus(static_cast<int>(Activity::Status::Finished));
        }
    }
}

void MainWindow::on_RemoveButton_clicked()
{
    for (int i = 0; i<m_tracker.getActivities().size(); ++i)
    {
        if(ui->ListNames->item(i)->isSelected())
        {
            m_tracker.getActivities().erase(m_tracker.getActivities().begin() + i);
        }
    }
    needToRefreshNames = true;
}

void MainWindow::on_actionSave_triggered()
{
    std::ofstream out("Log.txt");
    if(out.is_open())
    {
        out<<m_tracker.getActivities().size()<<'\n';
        for(int i = 0 ; i < m_tracker.getActivities().size(); ++i)
            out<<m_tracker.getActivities()[i].getName().toUtf8().constData()<<' '<<m_tracker.getActivities()[i].getDuration()<<'\n';
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
        for(size_t i = 0; i < static_cast<size_t>(size); ++i)
        {
            std::string name;
            double dur;
            in>>name;
            in>>line;
            dur = std::stod(line);
            m_tracker.addActivity(Activity(QString::fromUtf8(name.c_str()), dur));
        }
        needToRefreshNames = true;
    }
}
