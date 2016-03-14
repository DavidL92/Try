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
        virtual void register(int num,Colleague * col)
        {
        }
};

class ConcreteMediator : public Mediator
{
    public:
        void operation(int op)
        {
        }
        Colleague* register(int mWho,Colleague *col)
        {
            map<int,Colleague*>::const_iterator itr = m_mColleague.find(mWho);
            if(itr == m_mColleague.end())
            {
                m_mColleague.insert(make_pair(mWho,col));
            }
        }
    private:
        map<int,Colleague *> m_mColleague;
}

class ConcreteColleaguaA : public Colleague
{
    public:
        void sendmsg(int msg)
        {
        }
        void setMediator(Mediator *)
        {
        }
}
class ConcreteColleaguaB : public Colleague
{
    public:
        void sendmsg(int msg)
        {
        }
        void setMediator(Mediator *)
        {
        }
}

int main()
{
    Mediator * med = new ConcreteMediator();
    Colleague *col1 = new ConcreteColleaguaA();
    col1->setMediator(med);
}
