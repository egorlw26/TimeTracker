#ifndef TRACKER_H
#define TRACKER_H

#include "activity.h"
#include <QVector>

class Tracker
{
public:
    Tracker();
    void addActivity(const Activity& i_activity);
    void addActivity(QString i_name);
    QVector<Activity>& getActivities() {return m_activities;}
    void saveTracker();
    void loadTracker();
private:
    QVector<Activity> m_activities;
};

#endif // TRACKER_H
