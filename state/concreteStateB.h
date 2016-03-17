#include "state.h"
#include "context.h"
class ConcreteStateA;
class ConcreteStateB : public state
{
    public:
        virtual ~ConcreteStateB();
        static State * Instance();

        void handle(Context *);
        
    private:
        ConcreteStateB();
        static State* m_pState;
}
