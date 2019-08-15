#include "tracker.h"
#include <QFile>
#include <QTextStream>

Tracker::Tracker()
{
}

void Tracker::addActivity(const Activity &i_activity)
{
    m_activities.push_back(i_activity);
}

void Tracker::addActivity(QString i_name)
{
    if(i_name != "")
        m_activities.push_back(Activity(i_name));
}

void Tracker::saveTracker()
{
    QString filename = "Log.txt";
    QFile file(filename);
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        stream<<m_activities.size()<<'\n';
        for(int i = 0 ; i < m_activities.size(); ++i)
            stream<<m_activities[i].getName().toUtf8().constData()<<' '<<m_activities[i].getDuration()<<' '<<m_activities[i].getStatus()<<'\n';
    }
    file.close();
}

void Tracker::loadTracker()
{
    QString filename = "Log.txt";
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        size_t size;
        stream>>size;
        for (size_t i = 0; i < size; ++i)
        {
            QString a_name;
            double a_duration;
            int a_status;
            stream>>a_name>>a_duration>>a_status;
            addActivity(Activity(a_name, a_duration, a_status));
        }
    }
    file.close();
}
