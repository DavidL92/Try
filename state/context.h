
class Context
{
    public:
        Context();
        virtual ~Context();
        void changeState(State *);
        void request();
};
