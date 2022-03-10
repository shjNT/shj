#include<iostream>
using namespace std;

//静态成员
// 静态函数：
// ①所有对象共享同一个函数
// ②静态成员函数只能访问静态成员变量

class Person
{

public:
    static void func()
    {
        m_a = 100;
        // m_b = 200; // 静态成员函数不可以访问非静态成员变量
        cout << "static void func调用" << endl;
    }

    static int m_a;
    int m_b;
// 静态成员函数也有访问权限
private:
    static void func2()
    {
        cout << "static void func2" << endl;
    }
};

int Person::m_a = 0;

void test01()
{
    //1.通过对象访问
    Person p;
    p.func();
    // 2.通过类名访问
    Person::func();
}

void test02()
{
    // Person::func2();  //类外不能访问私有静态成员函数
}
int main()
{
    test01();
    return 0;
}