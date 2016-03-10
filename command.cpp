#include <iostream>

using namespace std;

class Command
{
    public:
        Command()
        {
        }
        virtual ~Command()
        {
            cout << "delete Command" << endl;
        }
        virtual void execute()
        {
            cout << "command.execute" << endl;
        }
};

class Receiver
{
    public:
        Receiver(){}
        ~Receiver(){cout << "delete receive " << endl;}
        void action()
        {
            cout << "Receiver.action" << endl;
        }
};

class ConcreteCommand : public Command
{
    public:
        ConcreteCommand(Receiver *r)
        {
            rec = r;
        }
        ~ConcreteCommand()
        {
            delete rec;
            cout << "delete ConcreteCommand" << endl;
        }
        void execute()
        {
            rec->action();
        }
    private:
        Receiver *rec;
    
};

class Invoker
{
    public:
        Invoker(Command *c)
        {
            com = c;
        }
        ~Invoker()
        {
            delete com;
            cout << "Delete Invoker" << endl;
        }
        void call()
        {
            com->execute();
        }
    private:
        Command *com;

};
int main()
{
    Receiver *pReceive = new Receiver();
    Command * pCommand = new ConcreteCommand(pReceive);
    Invoker * invoker = new Invoker(pCommand);
    invoker->call();
    delete invoker;
    return 0;
}
