#include<iostream>
using namespace std;

// 静态成员: 在成员变量和成员函数前加上static
// 静态成员变量:
// ①所有对象共享同一份数据
// ②在编译截断分配内存
// ③类内生成，类外初始化

class Person
{
public:
    static int m_a;

// 静态变量也有访问权限
private:
    static int m_b;
};
//类外初始化
int Person::m_a = 100;
int Person::m_b = 200;

void test01()
{
    Person p;
    cout << p.m_a << endl;

    Person p2;
    p2.m_a = 200;
    cout << p.m_a << endl;
}

void test02()
{
    // 静态成员变量不属于某个对象上，所有对象共享同一份数据，因此有两种访问方式
    // ①通过对象访问
    Person p;
    cout << p.m_a << endl;
    // ②通过类名访问
    cout << Person::m_a << endl;
    // cout << Person::m_b << endl; // 类外不能访问私有静态变量
}

int main()
{
    // test01();
    test02();
    return 0;
}