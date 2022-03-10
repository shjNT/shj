#include<iostream>
using namespace std;

// 运算负重载：对已有的运算符进行重新定义，赋予其另一种功能，以适应不同的数据类型

// 加号运算符重载 -> 实现两个自定义的数据类型相加运算


// 1.成员函数重载
class Person
{
public:

    // 成员函数重载加号
    // Person operator+(Person &p)
    // {
    //     Person tmp;
    //     tmp.m_a = this->m_a + p.m_a;
    //     tmp.m_b = this->m_b + p.m_b;
    //     return tmp;
    // }
    int m_a;
    int m_b;
};

// 2.全局函数重载加号
Person operator+(Person &p1, Person &p2)
{
    Person tmp;
    tmp.m_a = p1.m_a + p2.m_a;
    tmp.m_b = p2.m_b + p1.m_b;
    return tmp;
}

Person operator+(Person &p, int num)
{
    Person tmp;
    tmp.m_a = p.m_a + num;
    tmp.m_b = p.m_b + num;
    return tmp;
}

void test01()
{
    Person p1;
    p1.m_a = 10;
    p1.m_b = 10;
    Person p2;
    p2.m_a = 10;
    p2.m_b = 15;

    //成员函数的本质调用
    // Person p3 = p1.operator+(p2);
    // 全局函数的本质调用
    // Person p3 = operator+(p1, p2);
    Person p3 = p1 + p2;

    // 运算符重载也可以发生函数重载
    Person p4 = p1 + 101;
    cout << p3.m_a << endl;
    cout << p3.m_b << endl;
    cout << p4.m_a << endl;
    cout << p4.m_b << endl;
}

int main()
{
    test01();
    return 0;
}