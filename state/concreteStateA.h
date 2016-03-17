#include "state.h"
#include "context.h"
#include "concreteStateB.h"
class ConcreteStateA : public state
{
    public:
        virtual ~ConcreteStateA();
        static State * Instance();

        void handle(Context *);
        
    private:
        ConcreteStateA();
        static State* m_pState;
}
