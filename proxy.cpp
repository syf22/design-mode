//代理模式  为其他对象提供一种代理以控制对这个对象的访问
#include <iostream>
using namespace std;
class persuitepeople
{
public:
    string mm;
    persuitepeople(string lmm):mm(lmm){};
    virtual void persuit()=0;
};
class realpeople:public persuitepeople
{
public:
    realpeople(string lmm):persuitepeople(lmm){};
    virtual void persuit()
    {
        cout<<"喜欢你"<<mm<<endl;
    }
};
class peopleproxy:public persuitepeople
{
public:peopleproxy(string lmm):persuitepeople(lmm){};
    void persuit()
    {   realpeople* people=new realpeople(mm);
        people->persuit();
    }
};
int main()
{   string mm;
    cout<<"姓名"<<endl;
    cin>>mm;
    peopleproxy* proxy=new peopleproxy(mm);
    proxy->persuit();
    return 0;
}