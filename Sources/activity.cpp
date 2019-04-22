#include "activity.h"

Activity::Activity() :
    duration(0), status(0)
{
    start = clock();
}

Activity::Activity(std::string name) :
    name(name), duration(0), status(0)
{
    start = clock();
}

Activity::Activity(std::string name, double duration):
    name(name), duration(duration), status(0)
{

}

int Activity::getStatus()
{
    return status;
}

void Activity::setStatus(int nStatus)
{
    status = nStatus;
}

void Activity::update()
{
    if(status == 1)
    {
        duration += (double(clock() - start))/(double)CLOCKS_PER_SEC;
        start = clock();
    }
    if(status == -1)
    {
        duration = 0;
    }
}

QString Activity::getQStringName()
{
    return QString::fromStdString(this->name);
}
