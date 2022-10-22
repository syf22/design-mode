//单例模式 懒汉式   线程安全要加锁  单锁
#include <iostream>
#include <mutex>
using namespace std;

class singleton
{
private:
    singleton(){}
    singleton(const singleton &s){}

private:
    static singleton* m_singleton;
public:
    static singleton* getsingleton()  //饿汉式  直接return m_singleton
    {
        mutex m;//多线程时要加锁
        if(m_singleton== nullptr)
        {
            m_singleton=new singleton();
        }
        return m_singleton;
    }
};
singleton* singleton::m_singleton= nullptr;    //饿汉式 =new singleton
int main()
{
    singleton* s=singleton::getsingleton();  //静态成员函数可以用类名获取

    return 0;
}