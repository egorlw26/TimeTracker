#include "activity.h"

Activity::Activity() :
    m_duration(0), m_status(static_cast<int>(Status::Paused))
{
    m_start = clock();
}

Activity::Activity(QString i_name) :
    m_name(i_name), m_duration(0), m_status(static_cast<int>(Status::Paused))
{
    m_start = clock();
}

Activity::Activity(QString i_name, double i_duration):
    m_name(i_name), m_duration(i_duration), m_status(static_cast<int>(Status::Paused))
{

}

Activity::Activity(QString i_name, double i_duration, int i_status):
    m_name(i_name), m_duration(i_duration), m_status(i_status)
{

}

int Activity::getStatus()
{
    return m_status;
}

double Activity::getDuration()
{
    return m_duration;
}

QString Activity::getName()
{
    return m_name;
}

QString Activity::getStatusText()
{
    switch (m_status)
    {
    case static_cast<int>(Status::Paused):
        return QString("Paused");
    case static_cast<int>(Status::Started):
        return QString("Started");
    case static_cast<int>(Status::Finished):
        return QString("Finished");
    case static_cast<int>(Status::Restarted):
        return QString("Restarted");
    }
}

void Activity::setStatus(int i_status)
{
    m_status = i_status;
}

void Activity::setStartNow()
{
    m_start = clock();
}

void Activity::update()
{
    if(m_status == static_cast<int>(Status::Started))
    {
        m_duration += (double(clock() - m_start))/static_cast<double>(CLOCKS_PER_SEC);
        m_start = clock();
    }
    if(m_status == static_cast<int>(Status::Restarted))
    {
        m_duration = 0;
    }
    if(m_status == static_cast<int>(Status::Paused))
    { }
    if(m_status == static_cast<int>(Status::Finished))
    { }
}
