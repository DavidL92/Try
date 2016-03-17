#include "state.h"
class Context
{
    public:
        Context();
        virtual ~Context();
        void changeState(State *);
        void request();
    private:
        State * m_pState;
};
