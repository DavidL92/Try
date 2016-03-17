#include "context.h"

Context::Context()
{
    m_pState = new ConcreteStateA();
}

Context::~Context()
{
}
void Context::changeState(State* state)
{
    m_pState = state;
}
void Context::request()
{
    m_pState->handle(this);
}
