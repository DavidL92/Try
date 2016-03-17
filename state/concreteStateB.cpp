#include "concreteStateB.h"

ConcreteStateA::ConcreteStateB()
{
}
ConcreteStateA::~ConcreteStateB()
{
}
static State *ConcreteStateB::Instance()
{
    if(m_pState == NULL)
    {
        m_pState = new ConcreteStateB();
    }
    return m_pState;

}
void ConcreteStateB::handle(Context *c)
{
    cout << "doing something in State B.\n doen,change state to A" << endl;
    c->changeState(ConcreteStateA::Instance());
}
