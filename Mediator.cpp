#include <iostream>

using namespace std;

class Colleague
{
    public:
        Colleague(){}
        ~Colleague(){}
        void receivemsg()
        {
        }
        virtual void sendmsg(int a)
        {
        }
        void setMediator(Mediator *)
        {
        }
}

class Mediator
{
    public:
        Mediator(){}
        ~Mediator(){}
        virtual operation(int a){}
        virtual void register(Colleague * col)
        {
        }
};

class ConcreteColleaguaA : public
{
    
}
