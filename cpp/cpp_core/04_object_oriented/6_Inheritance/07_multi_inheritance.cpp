#include<iostream>
using namespace std;

// 多继承

// 语法：class 子类：继承方式 父类1， 继承方式 父类2，...

class Base1
{
public:
    Base1()
    {
        m_a = 100;
    }
    int m_a;

};
class Base2
{
public:
    Base2()
    {
        m_a = 200;
    }
    int m_a;
};

class Son: public Base1, public Base2
{
public:
    Son(){
        m_c = 300;
        m_d = 400;
    }
    int m_c;
    int m_d;
};


void test01()
{
    Son s;
    cout << sizeof(s) << endl;
    cout << s.Base1::m_a << endl;
    cout << s.Base2::m_a << endl;
}


int main()
{
    test01();
    return 0;
}