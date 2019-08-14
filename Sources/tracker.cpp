#include "tracker.h"

Tracker::Tracker()
{

}

void Tracker::addActivity(const Activity &i_activity)
{
    m_activities.push_back(i_activity);
}
