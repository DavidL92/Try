#include <iostream>
#include <string>
#include <map>

using namespace std;
class FlyWeight
{
    public:
        FlyWeight()
        {
        }
        virtual ~FlyWeight()
        {
        }
        virtual void operation()
        {
        }
};

class ConcreteFlyWeight : public FlyWeight
{
    public:
        ConcreteFlyWeight(string str)
        {
            intrinsicState = str;
        }
        ~ConcreteFlyWeight()
        {
        }
        void operation()
        {
            cout << "use[" << intrinsicState << "]operation" << endl;
        }
    private:
        string intrinsicState;
};

class FlyweightFactory
{
    public:
        FlyweightFactory()
        {
        }
        ~FlyweightFactory()
        {
        }
        FlyWeight *getFlyWeight(string str)
        {
            map<string,FlyWeight*>::iterator itr = m_mFlyWeight.find(str);
            if(itr == m_mFlyWeight.end())
            {
                FlyWeight *fw = new ConcreteFlyWeight(str);
                m_mFlyWeight.insert(make_pair(str,fw));
                return fw;
            }
            else
            {
                cout << "already in the pool,use the exist one:" << endl;
                return itr->second;
            }
        }
    private:
        map<string,FlyWeight*> m_mFlyWeight;
};

int main()
{
    FlyweightFactory *fwf = new FlyweightFactory();
    FlyWeight *fw = fwf->getFlyWeight("one");
    fw->operation();
    FlyWeight *fw1 = fwf->getFlyWeight("two");
    fw1->operation();
    FlyWeight *fw2 = fwf->getFlyWeight("one");
    fw2->operation();
}
