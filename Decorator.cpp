//装饰模式   在某个功能的基础上增加功能  继承+组合
#include <iostream>
using namespace std;
class computer
{
public:
    virtual void listenmusic()=0;
    virtual void wacthtv()=0;
};
class dellcomputer:public computer   //有基础功能的某个类
{
public:
    virtual void listenmusic()
    {
        cout<<"用dell电脑听音乐";
    }
    virtual void wacthtv() {
        cout << "用dell电脑看电视";
    }
};
class hpcomputer:public computer
{
public:
    virtual void listenmusic()
    {
        cout<<"用hp电脑听音乐";
    }
    virtual void wacthtv() {
        cout << "用hp电脑看电视";
    }
};
class decorator:public computer    //抽象装饰类   要给哪个基础功能装饰哪个装设   继承加组合
{
protected:
    computer* com;
public:
    decorator():com(nullptr){};
    decorator(computer* m):com(m){};
    virtual void listenmusic()
    {
        com->listenmusic();
    }
    virtual void wacthtv()
    {
        com->wacthtv();
    }
};
class daireji:public decorator
{
public:
    daireji(computer* m):decorator(m){};
    virtual void listenmusic()
    {   cout<<"带耳机";
        com->listenmusic();
    }
    virtual void wacthtv()
    {   cout<<"带耳机";
        com->wacthtv();
    }
};
class touyin:public decorator
{
public:
    virtual void listenmusic()
    {   cout<<"投影";
        com->listenmusic();
    }
    virtual void wacthtv()
    {   cout<<"投影";
        com->wacthtv();
    }
};
int main()
{    dellcomputer* dell=new dellcomputer();
    daireji* dec=new daireji(dell);
    return 0;

}