#ifndef TRACKER_H
#define TRACKER_H

#include "activity.h"
#include <QVector>

class Tracker
{
public:
    Tracker();
    void addActivity(const Activity& activity);
    QVector<Activity>& getActivities() {return m_activities;}
private:
    QVector<Activity> m_activities;
};

#endif // TRACKER_H
