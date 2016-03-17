#include <subject.h>
#include <vector>
Subject::Subject()
{
}
Subject::~Subject()
{
}
void Subject::Attach(Observer *obj)
{
    m_observer.push_back(obj);
}
void Subject::Detach(Observer *obj)
{
    for(vector<Observer *>::iterator itr = m_observer.begin();itr != m_observer.end();itr++)
    {
        if((*itr) == obj)
        {
            m_observer.erase(itr);
            return;
        }
    }
    cout << "unable to find this object" << endl;
}
void Subject::Notify()
{
    for(vector<Observer *>::iterator itr = m_observer.begin();itr != m_observer.end();itr++)
    {
        (*itr)->update(this);
    }
}
