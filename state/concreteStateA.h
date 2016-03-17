#include "concreteStateB.h"
class ConcreteStateA : public State
{
    public:
        virtual ~ConcreteStateA();
        static State * Instance();

        void handle(Context *);
        
    private:
        ConcreteStateA();
        static State* m_pState;
};
