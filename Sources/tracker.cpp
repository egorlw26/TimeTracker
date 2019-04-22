#include "tracker.h"

Tracker::Tracker()
{

}

void Tracker::addActivity(const Activity &activity)
{
    m_activities.push_back(activity);
}
