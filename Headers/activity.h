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
        Restarted = -1,
        Paused = 0,
        Started = 1,
        Finished = 2
    };
    Activity();
    Activity(QString name);
    Activity(QString name, double duration);
    Activity(QString name, double duration, int status);
    int getStatus();
    double getDuration();
    QString getName();
    QString getStatusText();
    void setStatus(int nStatus);
    void setStartNow();
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
