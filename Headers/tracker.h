#ifndef TRACKER_H
#define TRACKER_H

#include "activity.h"
#include <vector>
#include <thread>

class Tracker
{
public:
    Tracker();
    void addActivity(const Activity& activity);
    std::vector<Activity>& getActivities() {return m_activities;}
private:
    std::vector<Activity> m_activities;
};

#endif // TRACKER_H
