#include <iostream>

using namespace std;

class SysteamA
{
    public:
        SysteamA()
        {
        }
        ~SysteamA()
        {
        }
        void operationA()
        {
            cout << "opeartaionA" << endl;
        }
};
class SysteamB
{
    public:
        SysteamB()
        {
        }
        ~SysteamB()
        {
        }
        void operationB()
        {
            cout << "opeartaionB" << endl;
        }
};
class SysteamC
{
    public:
        SysteamC()
        {
        }
        ~SysteamC()
        {
        }
        void operationC()
        {
            cout << "opeartaionC" << endl;
        }
};



class Facade
{
    public:
        Facade()
        {
            m_SysteamA = new SysteamA();
            m_SysteamB = new SysteamB();
            m_SysteamC = new SysteamC();
        }
        ~Facade()
        {
            delete m_SysteamA;
            delete m_SysteamB;
            delete m_SysteamC;
        }
        void wrapOperation()
        {
            m_SysteamA->operationA();
            m_SysteamB->operationB();
            m_SysteamC->operationC();
            
        }
    private:
        SysteamA *m_SysteamA;
        SysteamB *m_SysteamB;
        SysteamC *m_SysteamC;
};
int main()
{
    Facade *facade = new Facade();
    facade->wrapOperation();
    return 1;
}
