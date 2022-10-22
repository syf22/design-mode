//工厂方法模式  //new多态  去掉具体类依赖
#include <iostream>
using namespace std;

class fuzhuang     //对象基类
{
public:
    virtual void  shangping() = 0;
    ~fuzhuang();
};
class duanxiu :public fuzhuang
{
public:
    void shangping()
    {
        cout << "生产短袖";
    }
};
class kuzi :public fuzhuang
{
public:
    void shangping()
    {
        cout << "生产裤子";
    }
};
class hat :public fuzhuang
{
public:
    void shangping()
    {
        cout << "生产hat";
    }
};
class factory  //工厂基类
{
public:
    virtual fuzhuang* creatfuzhuang() = 0;
    ~factory();
};
class duanxiufactory :public factory
{
public:
    virtual fuzhuang* creatfuzhuang()
    {
        return new duanxiu();
    }
};
class kuzifactory :public factory
{
public:
    virtual fuzhuang* creatfuzhuang()
    {
        return new kuzi();
    }
};
class hatfactory :public factory
{
public:
    virtual fuzhuang* creatfuzhuang()
    {
        return new hat();
    }
};
class guke    //只依赖两个抽象类
{
public:
    factory* f;
    guke(factory* ff) :f(ff) {};
    void requst()
    {
        fuzhuang* fu = f->creatfuzhuang();
        fu->shangping();
    }
};
int main()
{
    factory* f = new duanxiufactory();
    guke* g = new guke(f);
    g->requst();
    return 0;
}