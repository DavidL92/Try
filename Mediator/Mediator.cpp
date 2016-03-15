#include <iostream>
#include <map>
#include <string>

using namespace std;


class Mediator
{
    public:
        Mediator(){}
        ~Mediator(){}
        virtual void operation(int a,string msg){}
        virtual void registe(int num,Colleague * col)
        {
        }
};
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
}

class ConcreteMediator : public Mediator
{
    public:
        void operation(int mWho,string op)
        {
            map<int,Colleague*>::const_iterator itr = m_mColleague.find(mWho);
            if(itr == m_mColleague.end())
            {
                cout << "not found this user" << endl;
                return;
            }
            Colleague *pc = itr->second;
            pc->receivemsg(str);
        }
        Colleague* registe(int mWho,Colleague *col)
        {
            map<int,Colleague*>::const_iterator itr = m_mColleague.find(mWho);
            if(itr == m_mColleague.end())
            {
                m_mColleague.insert(make_pair(mWho,col));
            }
        }
    private:
        map<int,Colleague *> m_mColleague;
};

class ConcreteColleaguaA : public Colleague
{
    public:

        void sendmsg(int toWho,int msg)
        {
            cout << "send msg from ColleagueA,to:" << toWho << endl;
            mediator->operation(toWho,msg);
        }
        void setMediator(Mediator * med)
        {
            mediator = med;
        }
        void receivemsg(string msg)
        {
            cout << "ColleagueA has received msg:" << msg << endl;
        }
    private:
        Mediator * mediator;
};
class ConcreteColleaguaB : public Colleague
{
    public:
        void sendmsg(int msg)
        {
            cout << "send msg from ColleagueB,to:" << toWho << endl;
            mediator->operation(toWho,msg);
        }
        void setMediator(Mediator * med)
        {
            mediator = med;
        }
        void receivemsg(string msg)
        {
            cout << "ColleagueB has received msg:" << msg << endl;
        }
    private:
        Mediator *mediator;
};

int main()
{
    Mediator * med = new ConcreteMediator();
    Colleague *col1 = new ConcreteColleaguaA();
    Colleague *col2 = new ConcreteColleaguaA();
    med->registe(1,col1);
    med->registe(2,col2);
    col1->sendmsg(2,"hello,i am 1");
    col1->sendmsg(1,"hello,i am 2");
    return 1;
}
