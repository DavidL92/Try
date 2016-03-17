#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Colleague 
{
    public:
        Colleague(string n)
        {
            name = n;
        }
        virtual ~Colleague()
        {
        }
        void set_content(string n)
        {
            say = n;
        }
        void talk()
        {
            cout << say << endl;
        }
    private:
        string say;
        string name;
};

class Moniter : public Colleague
{
    public:
        Moniter(string n = " ") : Colleague(n)
        {
        }
        ~Moniter()
        {
        }
};

class StudentA : public Colleague
{
    public:
        StudentA(string n = " ") : Colleague(n)
        {
        }
        ~StudentA()
        {
        }
};

class StudentB : public Colleague
{
    public:
        StudentB(string n = " ") : Colleague(n)
        {
        }
        ~StudentB()
        {
        }
};

class Mediator
{
    public:
        Mediator()
        {
        }
        ~Mediator()
        {
        }
        virtual void AddStudent(Colleague * colleague)
        {
        }
        virtual void chart()
        {
        }

};

class TestMediator : public Mediator
{
    public:
        TestMediator()
        {
        }
        ~TestMediator()
        {
        }
        void AddStudent(Colleague * colleague)
        {
            vector<Colleague *>::iterator itr = find(m_vColleague.begin(),m_vColleague.end(),colleague);
            if(itr == m_vColleague.end())
            {
                m_vColleague.push_back(colleague);
            }
            else
            {
                cout << "This student has join this room" << endl;
            }
        }
        void chart()
        {
            vector<Colleague *>::iterator itr = m_vColleague.begin();
            for(;itr != m_vColleague.end();itr++)
            {
                (*itr)->talk();
            }
        }
    private:
        vector<Colleague *> m_vColleague;
        
};

int main()
{
    Colleague *moniter = new Moniter("Jerry");
    Colleague *studentA = new StudentA("Tom");
    Colleague *studentB = new StudentB("Jack");

    Mediator * testmediator = new TestMediator(); 
    testmediator->AddStudent(moniter);
    testmediator->AddStudent(studentA);
    testmediator->AddStudent(studentB);
    moniter->set_content("hello everyone,we have a meeting");
    studentA->set_content("mamamiya");
    studentB->set_content("come on");
    testmediator->chart();
    return 0;
}
