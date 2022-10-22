#include<iostream>
using namespace std;

//责任链模式
class  hander   //基础接口   控制处理对象个数和处理顺序
{
public:
    hander* next;
    hander() :next(nullptr) {}

    virtual bool handerrequst(int requst)
    {
        return true;
    }
    virtual bool canhandrequst(int requst) {
        return true;
    }
    hander* getnexthander()
    {
        return next;
    }
    void setnexthandr(hander* n)
    {
        next = n;
    }
    void sendReqestToNextHandler(int requst)
    {
        if (next!= nullptr)
            next->hand(requst);
    }
    void hand(int resqut)    //判断当前对象能否处理
    {
        if (canhandrequst(resqut))
            handerrequst(resqut);
        else
            sendReqestToNextHandler(resqut); //不能处理将请求发送给下一个对象

    }
    static void handershunxu(int requst);

};
class qiantai :public hander
{
public:

    virtual bool handrequst(int resqut)
    {
        cout << "前台准假" << endl;
        return true;

    }
    virtual bool canhandrequst(int  requst)
    {
        if (requst <= 1)
        {
            this->handrequst(requst);
            return true;
        }
        return false;

    }
};
class zhuguan :public hander
{
public:

    virtual bool handrequst(int resqut)
    {
        cout << "主管准假" << endl;
        return true;
    }
    virtual bool canhandrequst(int  requst)
    {
        if (requst <= 3 && requst > 1)
        {
            this->handrequst(requst);
            return true;
        }
        return false;
    }
};
class boss :public hander
{
public:

    virtual bool handrequst(int resqut)
    {
        cout << "老板准假" << endl;
        return true;
    }
    virtual bool canhandrequst(int  requst)
    {
        if (requst > 3)
        {
            this->handrequst(requst);
            return true;
        }
        return false;
    }
};
void hander::handershunxu(int requst)//扩展
{
    hander* h0 = new qiantai();
    hander* h1 = new zhuguan();
    hander* h2 = new boss();
    h0->setnexthandr(h1);
    h1->setnexthandr(h2);
    h0->hand(requst);
}
int main()
{
    cout << "请输入请假天数" << endl;
    int requst;
    cin >> requst;
    hander* liucheng = new hander();
    liucheng->handershunxu(requst);
    return 0;
}