#include <iostream>
#include <vector>
#include "subject.h"

using namespace std;

class ConcreteSubjectA : public Subject
{
    public:
        ConcreteSubjectA()
        {
        }
        ~ConcreteSubjectA()
        {
        }
        void set_state(string n)
        {
            state = n;
        }
        string get_state()
        {
            return state;
        }
    private:
        string state;
};
class ConcreteSubjectB : public Subject
{
    public:
        ConcreteSubjectB()
        {
        }
        ~ConcreteSubjectB()
        {
        }
        void set_state(string n)
        {
            state = n;
        }
        string get_state()
        {
            return state;
        }
    private:
        string state;
};
class ConcreteObserverA : public Observer
{
    public:
        void update(Subject *subject)
        {
            cout << "ObserverA :" << subject->get_state() << endl;
        }
};

class ConcreteObserverB : public Observer
{
    public:
        void update(Subject *subject)
        {
            cout << "ObserverB :" << subject->get_state() << endl;
        }
};
int main()
{
    Observer *observea = new ConcreteObserverA();
    Observer *observeb = new ConcreteObserverB();
    Subject *SubjectA = new ConcreteSubjectA();
    Subject *SubjectB = new ConcreteSubjectB();

    SubjectA->Attach(observea);
    SubjectA->Attach(observeb);
    SubjectA->set_state("abc");
    SubjectA->Notify();
    SubjectA->Detach(observeb);
    SubjectA->Notify();

}
