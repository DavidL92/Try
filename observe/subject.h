#include <string>
#include "observe.h"

using namespace std;
class Subject
{
    public:
        Subject();
        virtual ~Subject();
        void Attach(Observer *);
        void Detach(Observer *);
        void Notify();
        virtual void set_state(string) = 0;
        virtual string get_state() = 0;
    private:
        vector<Observer *> m_observer;
};
