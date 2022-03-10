#include<iostream>
using namespace std;

// 继承同名成员处理方式
// ①访问子类同名成员，直接访问；②访问父类同名成员，需加作用域

class Base
{
public:
    Base()
    {
        m_a = 100;
    }

    void func()
    {
        cout << "base下的func调用" << endl;
    }


    void func(int a)
    {
        cout << "base下的func(int a)调用" << endl;
    }

    int m_a;
};

class Son: public Base
{
public:
    Son()
    {
        m_a = 200;
    }

    void func()
    {
        cout << "son下的func调用" << endl;
    }


    int m_a;
};

void test01()
{
    Son s;
    cout << s.m_a << endl;
    // 若想通过子类对象访问父类的同名属性，应加父类的作用域
    cout << s.Base::m_a << endl;
}

void test02()
{
    Son s;
    s.func();
    // 若想通过子类对象访问父类的同名函数，应加父类的作用域
    s.Base::func();
    s.Base::func(1);  // 若子类出现和父类的同名函数，那么所有的父类同名成员函数(函数重载)会被编译器隐藏
}

int main()
{
    // test01();
    test02();
    return 0;
}