#include "context.h"
class ConcreteStateB : public State
{
    public:
        virtual ~ConcreteStateB();
        static State * Instance();

        void handle(Context *);
        
    private:
        ConcreteStateB();
        static State* m_pState;
};
