#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
#include <QString>
#include <chrono>

class Activity
{
public:
    enum class Status : int
    {
        Finished = -1,
        Paused = 0,
        Started = 1
    };
    Activity();
    Activity(QString name);
    Activity(QString name, double duration);
    int getStatus();
    double getDuration() {return m_duration;}
    QString getName() {return m_name;}
    void setStatus(int nStatus);
    void setStartNow() {m_start = clock();}
    void update();
private:
    void addSecond();

private:
    QString m_name;
    double m_duration;
    int m_status;
    clock_t m_start;
};

#endif // ACTIVITY_H
