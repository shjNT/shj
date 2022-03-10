#include<iostream>
using namespace std;

// 继承同名的静态成员处理方式

// 访问子类同名成员，直接访问；访问父类同名成员，加作用域

class Base
{
public:
    static int m_a;
    static void func()
    {
        cout << "base 的func()" << endl;
    }
};
int Base::m_a = 100;

class Son: public Base
{
public:
    static int m_a;
    static void func()
    {
        cout << "son 的func()" << endl;
    }
};
int Son::m_a = 200;

void test01()
{
    // 通过对象访问静态成员属性
    Son s;
    cout << s.m_a << endl;
    cout << s.Base::m_a << endl;

    // 通过类名访问静态成员属性
    cout << Son::m_a << endl;
    cout << Son::Base::m_a << endl;
};

void test02()
{
    // 对象调用
    Son s;
    s.func();
    s.Base::func();

    // 类名调用
    Son::func();
    Son::Base::func();

}

int main()
{
    // test01();
    test02();
    return 0;
}