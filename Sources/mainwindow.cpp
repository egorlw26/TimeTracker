#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "fstream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    needToRefreshNames(false),
    needToRefreshStatuses(false)
{
    ui->setupUi(this);
    mp_timer = new QTimer(this);
    connect(mp_timer, SIGNAL(timeout()), this, SLOT(Tick()));
    connect(ui->StopButton, &QAbstractButton::clicked, this, &MainWindow::PauseActivity);
    connect(ui->StartButton, &QAbstractButton::clicked, this, &MainWindow::StartActivity);
    connect(ui->RestartButton, &QAbstractButton::clicked, this, &MainWindow::RestartActivity);
    connect(ui->RemoveButton, &QAbstractButton::clicked, this, &MainWindow::RemoveActivity);
    connect(ui->FinishButton, &QAbstractButton::clicked, this, &MainWindow::FinishActivity);
    mp_timer->start(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Tick()
{
            if(needToRefreshNames)
                ui->ListNames->clear();
            if(needToRefreshStatuses)
                ui->ListStatuses->clear();
            ui->ListTimes->clear();
            for(int i = 0; i < m_tracker.getActivities().size(); ++i)
            {
                if(needToRefreshNames)
                    ui->ListNames->addItem(m_tracker.getActivities()[i].getName());
                if(needToRefreshStatuses)
                     ui->ListStatuses->addItem(m_tracker.getActivities()[i].getStatusText());
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
            needToRefreshStatuses = false;
}

void MainWindow::CreateActivity(QString i_name)
{
    m_tracker.addActivity(i_name);
}

void MainWindow::StartActivity()
{
    for(int i = 0; i<m_tracker.getActivities().size(); ++i)
    {
        if(ui->ListNames->item(i)->isSelected())
        {
            m_tracker.getActivities()[i].setStatus(static_cast<int>(Activity::Status::Started));
            m_tracker.getActivities()[i].setStartNow();
        }
    }
    needToRefreshStatuses = true;
}

void MainWindow::PauseActivity()
{
    for(int i = 0; i < m_tracker.getActivities().size(); ++i)
    {
       if(ui->ListNames->item(i)->isSelected())
       {
           m_tracker.getActivities()[i].setStatus(static_cast<int>(Activity::Status::Paused));
       }
    }
    needToRefreshStatuses = true;
}

void MainWindow::RestartActivity()
{
    for(int i = 0; i<m_tracker.getActivities().size(); ++i)
    {
        if(ui->ListNames->item(i)->isSelected())
        {
            m_tracker.getActivities()[i].setStatus(static_cast<int>(Activity::Status::Restarted));
        }
    }
    needToRefreshStatuses = true;
}

void MainWindow::RemoveActivity()
{
    for(int i = 0; i<m_tracker.getActivities().size(); ++i)
    {
        if(ui->ListNames->item(i)->isSelected())
        {
            m_tracker.getActivities().erase(m_tracker.getActivities().begin() + i);
        }
    }
    needToRefreshNames = true;
    needToRefreshStatuses = true;
}

void MainWindow::FinishActivity()
{
    for(int i = 0; i<m_tracker.getActivities().size(); ++i)
    {
        if(ui->ListNames->item(i)->isSelected())
        {
            m_tracker.getActivities()[i].setStatus(static_cast<int>(Activity::Status::Finished));
        }
    }
    needToRefreshStatuses = true;
}

void MainWindow::on_AddButton_clicked()
{
    Dialog d(this);
    d.exec();
    needToRefreshNames = true;
}


void MainWindow::on_actionSave_triggered()
{
    m_tracker.saveTracker();
}

void MainWindow::on_actionLoad_triggered()
{
    m_tracker.loadTracker();
    needToRefreshNames = true;
    needToRefreshStatuses = true;
}
