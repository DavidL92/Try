#include <iostream>
class State
{
    public:
        State();
        virtual ~State();
        virtual void handle();
};
