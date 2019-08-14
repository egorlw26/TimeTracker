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
    double getDuration() {return duration;}
    QString getName() {return name;}
    void setStatus(int nStatus);
    void setStartNow() {start = clock();}
    void update();
private:
    void addSecond();
    QString name;
    double duration;
    int status;
    clock_t start;
};

#endif // ACTIVITY_H
