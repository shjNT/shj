#include<iostream>
using namespace std;

// 左移运算符重载 ： 可以输出自定义输出类型

class Person
{
    friend ostream& operator<<(ostream &cout, Person &p);
    friend void test01();
private:
    // 利用成员函数重载左移运算符 -->> 一般不用
    // void operator<<(Person &p)
    // {

    // }
    int m_a;
    int m_b;
};

// 全局函数重载左移运算符
ostream& operator<<(ostream &cout, Person &p)
{
    cout << "p.m_a=" << p.m_a << "\t" << "p.m_b=" << p.m_b;
    return cout;
}

void test01()
{
    Person p;
    p.m_a = 10;
    p.m_b = 10;

    cout << p << endl; 
     
}


int main()
{
    test01();
    return 0;
} 