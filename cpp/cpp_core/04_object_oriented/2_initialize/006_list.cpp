#include<iostream>
using namespace std;

// 初始化列表: 用来初始化属性
// 语法： 构造函数():属性1(值1)，属性2(值2)...{}


class Person
{
public:
    // 传统初始化
    // Person(int a, int b, int c)
    // {
    //     m_a = a;
    //     m_b = b;
    //     m_c = c;
    // };

    // 初始化列表
    Person(int a, int b, int c): m_a(a), m_b(b), m_c(c)
    {
        
    }

public:
    int m_a;
    int m_b;
    int m_c;
};


void test01()
{
    // Person p(10, 20, 30);
    Person p(22, 3, 4);
    cout << p.m_a << endl;
    cout << p.m_b << endl;
    cout << p.m_c << endl;
};

int main()
{
    test01();
    return 0;
}