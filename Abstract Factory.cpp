//抽象工厂    多系列对象构建 一次创建一系列对象
#include <iostream>
using namespace std;
class shouji  //手机抽象类
{
public:
    virtual void show()=0;
};
class huaweishouji:public shouji
{
public:
    virtual void show()
    {
        cout<<"huaweishouji"<<endl;
    }
};
class xiaomishouji:public shouji
{
public:
    virtual void show()
    {
        cout<<"xiaomishouji"<<endl;
    }
};
class luyouqi
{
public:
    virtual void show()=0;
};
class huaweiluyouqi:public luyouqi
{
public:
    virtual void show()
    {
        cout<<"huaweiluyouqi"<<endl;
    }
};
class xiaomiluyouqi:public luyouqi
{
public:
    virtual void show()
    {
        cout<<"xiaomiluyouqi"<<endl;
    }
};
class factory  //工厂抽先类
{
public:
    virtual shouji* creatshouji()=0;
    virtual luyouqi* creatluyouqi()=0;
};
class huaweifactory:public factory
{
public:
    virtual shouji* creatshouji()
    {
        return new huaweishouji;
    }
    virtual luyouqi* creatluyouqi()
    {
        return new huaweiluyouqi;
    }
};
class xiaomifactory:public factory
{
public:
    virtual shouji* creatshouji()
    {
        return new xiaomishouji;
    }
    virtual luyouqi* creatluyouqi()
    {
        return new xiaomiluyouqi;
    }
};

class client {
public:
    factory *f;
    client(factory* ff):f(ff)
    {

    }
    void luyouqishow() {
        f->creatluyouqi()->show();
    }

    void shoujishow() {
        f->creatshouji()->show();
    }
};
int main()
{

    factory* f=new huaweifactory();
    client* c=new client(f);
    c->luyouqishow();
    c->shoujishow();
    return 0;

}