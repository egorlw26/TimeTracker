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

int Activity::getStatus()
{
    return m_status;
}

void Activity::setStatus(int i_status)
{
    m_status = i_status;
}

void Activity::update()
{
    if(m_status == static_cast<int>(Status::Started))
    {
        m_duration += (double(clock() - m_start))/static_cast<double>(CLOCKS_PER_SEC);
        m_start = clock();
    }
    if(m_status == static_cast<int>(Status::Finished))
    {
        m_duration = 0;
    }
    if(m_status == static_cast<int>(Status::Paused))
    { }
}
