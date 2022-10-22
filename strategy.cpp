#include <iostream>
using namespace std;
class zhekou
{
public:
    virtual double zhekounum(double& mony) = 0;
    //virtual ~zhekou() = 0;

};
class guoqing :public zhekou
{
public:
    virtual double zhekounum(double& mony)
    {
        mony = mony * 0.8;
        return mony;
    }

};
class zhongqiu :public zhekou
{
public:
    virtual double zhekounum(double& mony)
    {
        mony = mony * 0.7;
        return mony;
    }
};
class chunjie :public zhekou
{
public:
    virtual double zhekounum(double& mony)
    {
        mony = mony * 0.9;
        return mony;
    }
};
class shangchang
{
private:
    zhekou* zhe;//!!!!!!!
public:
    shangchang(zhekou* z)
    {
        zhe = z;
    }
    double resmony(double& mony)
    {
        zhe->zhekounum(mony);
        return mony;
    }
};
int main()
{
    zhekou* p = new guoqing();
    double m = 100;
    shangchang* s = new shangchang(p);
    int num = s->resmony(m);
    cout << "总共" << num << "元";
    return 0;
}