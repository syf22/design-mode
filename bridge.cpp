//桥接模式   多个维度抽象
#include<iostream>
using namespace std;
class linjian;
class che        //抽象接口  组合了另一个抽象接口
{
public:
    che()
    {
    }
    che(linjian* lin)
    {
        l = lin;
    }
    virtual void car() = 0;
    virtual  void bus() = 0;
    virtual void texi() = 0;
    linjian* l;

};
class linjian
{
public:

    virtual void fadongji() = 0;
    virtual void chelun() = 0;
};
class Achang :public che
{

public:
    Achang(linjian* lin)
    {
        l=lin;
    }
    void car()
    {
        cout << "Achangcar" << endl;
    }
    void bus()
    {
        cout << "Achangbus" << endl;
    }
    void texi()
    {
        cout << "Achangtexi" << endl;
    }
};
class Bchang :public che
{
public:
    void car()
    {
        cout << "Bchangcar" << endl;
    }
    void bus()
    {
        cout << "Bchangbus" << endl;
    }
    void texi()
    {
        cout << "Bchangtexi" << endl;
    }
};
class Cchanglin :public linjian
{
public:

    void fadongji()
    {
        cout << "Cchangfadongji" << endl;
    }
    void chelun()
    {
        cout << "Cchangchelun" << endl;
    }
};
class Dchanglin :public linjian
{
public:
    void fadongji()
    {
        cout << "Dchangfadongji" << endl;
    }
    void chelun()
    {
        cout << "Dchangchelun" << endl;
    }
};
int main()
{
    linjian* lin =new Cchanglin();
    che* c = new Achang(lin);
    c->bus();

    return 0;
}