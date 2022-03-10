#include<iostream>
using namespace std;

// 纯虚函数和抽象类
// 纯虚函数语法： virtual 返回值类型 函数名(参数列表) = 0;
// 当类中有了纯虚函数，这个类也称为抽象类

// 抽象类特点:
// ①无法实例化对象；②子类必须重写抽象类中的纯虚函数，否则也属于抽象类；


class Base // 抽象类
{
public:
    // 纯虚函数
    virtual void fun() = 0;
};

class Son: public Base
{
public:
    // 子类必须重写抽象类中的纯虚函数，否则也属于抽象类
    void fun()
    {
        cout << "fuck" << endl;
    }
};


void test01()
{
    // Base b;  //栈区抽象类无法实例化对象
    // new Base;    //堆区抽象类无法实例化对象

    // Son s;
    
    //多态调用
    Base * b = new Son;
    b->fun();

}

int main()
{
    test01();
    return 0;
}