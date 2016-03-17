#include "concreteStateA.h"

ConcreteStateA::ConcreteStateA()
{
}
ConcreteStateA::~ConcreteStateA()
{
}
static State *ConcreteStateA::Instance()
{
    if(m_pState == NULL)
    {
        m_pState = new ConcreteStateA();
    }
    return m_pState;
}
void ConcreteStateA::handle(Context *c)
{
    cout << "doing something in State A.\n done,change state to B" << endl;
    c->changeState(ConcreteStateB::Instance());
}
