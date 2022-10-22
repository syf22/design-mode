#include <iostream>
#include <list>
using namespace std;

class isplay//基础接口 一对多中的多
{
public:
    virtual void show(string s) = 0;
    virtual ~isplay() {}
};
class deviceA :public isplay
{
public:
    virtual void show(string s)
    {
        cout << "A" << s;
    }
};
class deviceB :public isplay
{
public:
    virtual void show(string s)
    {
        cout << "B" << s;
    }
};
class deviceC :public isplay
{
public:
    virtual void show(string s)
    {
        cout << "C" << s;
    }
};
class datacentr//主题对象 一对多中的一
{
private:
    list<isplay*>  devicelist;
public:
    void adddevice(isplay* p)
    {
        devicelist.push_back(p);

    }
    void removedevice(isplay* p)
    {
        devicelist.remove(p);
    }
    void tongzhi(string s)
    {
        for (auto d : devicelist)
        {
            d->show(s);
        }
    }
};
int main()
{
    datacentr centr;
    isplay* qq = new deviceA();
    isplay* weixin = new deviceB();
    centr.adddevice(qq);
    centr.adddevice(weixin);
    string s;
    cout << "天气" << endl;
    cin>>s;
    centr.tongzhi(s);
    return 0;
}