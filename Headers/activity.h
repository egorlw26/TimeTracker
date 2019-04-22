#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
#include <QString>
#include <thread>
#include <chrono>

class Activity
{
public:
    Activity();
    Activity(std::string name);
    Activity(std::string name, double duration);
    int getStatus();
    QString getQStringName();
    double getDuration() {return duration;}
    std::string getName() {return name;}
    void setStatus(int nStatus);
    void setStartNow() {start = clock();}
    void update();
private:
    void addSecond();
    std::string name;
    int status;
    double duration;
    clock_t start;
};

#endif // ACTIVITY_H
