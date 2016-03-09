#include <iostream>
#include <string>

using namespace std;

class Product
{
    public:
    void Add(string t)
    {
        text += t;
    }
    void show()
    {
        cout << text << endl;
    }
    private:
    string text;
};

class Builder
{
    public:
        virtual void buildPartA(){}
        virtual void buildPartB(){}
        virtual void buildPartC(){}
        virtual Product* getResult()
        {
            cout << "build complete" << endl;
        }
};
class ConcreteBuilder : public Builder
{
    public:
        ConcreteBuilder()
        {
            m_pro = new Product();
        }
        void buildPartA()
        {
            m_pro->Add("A");
        }
        void buildPartB()
        {
            m_pro->Add("B");
        }
        void buildPartC()
        {
            m_pro->Add("C");
        }
        Product* getResult()
        {
            return m_pro;
        }
    private:
        Product * m_pro;
        
};

class Director
{
    public:
        Director()
        {
        }
        ~Director()
        {
        }
        Product * constuct()
        {
            pbuilder->buildPartA();
            pbuilder->buildPartB();
            pbuilder->buildPartC();
            return pbuilder->getResult(); 
        }
        void setBuilder(Builder *builder)
        {
            pbuilder = builder;
        }
    private:
        Builder * pbuilder;
};

int main()
{
    Builder * builder = new ConcreteBuilder();
    Director director;
    director.setBuilder(builder);
    Product *pd = director.constuct();
    pd->show();

    delete builder;
    delete pd;
    return 0;
}
