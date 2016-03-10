#include <iostream>

using namespace std;

class Subject
{
    public:
        Subject()
        {
        }
        virtual ~Subject()
        {
        }
        virtual void request()
        {
            cout << "Subject.request" << endl;
        }

};

class RealSubject : public Subject
{
    public:
        RealSubject()
        {
        }
        ~RealSubject()
        {
        }
        void request()
        {
            cout << "RealSubject.request" << endl;
        }
};

class Proxy : public Subject
{
    public:
        Proxy()
        {
            rs = new RealSubject();
        }
        ~Proxy()
        {
            delete rs;
            cout << "rs is deleted" << endl;
        }
        void prerequest()
        {
            cout << "prerequest" << endl;
        }
        void afterrequest()
        {
            cout << "afterrequest" << endl;
        }
        void request()
        {
            prerequest();
            rs->request();
            afterrequest();
        }
    private:
        RealSubject *rs;
};

int main()
{
    Proxy * proxy = new Proxy();
    proxy->request();

    delete proxy;
    cout << "delete proxy" << endl;
    return 1;
}
