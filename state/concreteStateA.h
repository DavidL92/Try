#include "state.h"
class ConcreteStateA : public state
{
    public:
        virtual ~ConcreteStateA();
        static State * Instance();

        virtual void handle(Context *c);
        
    private:
        ConcreteStateA();
        static State* m_pState;
}
