#include "activity.h"

Activity::Activity() :
    duration(0), status(static_cast<int>(Status::Paused))
{
    start = clock();
}

Activity::Activity(QString name) :
    name(name), duration(0), status(static_cast<int>(Status::Paused))
{
    start = clock();
}

Activity::Activity(QString name, double duration):
    name(name), duration(duration), status(static_cast<int>(Status::Paused))
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
    if(status == static_cast<int>(Status::Started))
    {
        duration += (double(clock() - start))/static_cast<double>(CLOCKS_PER_SEC);
        start = clock();
    }
    if(status == static_cast<int>(Status::Finished))
    {
        duration = 0;
    }
    if(status == static_cast<int>(Status::Paused))
    {

    }
}
