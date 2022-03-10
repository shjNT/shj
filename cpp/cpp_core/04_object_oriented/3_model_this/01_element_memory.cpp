#include<iostream>
using namespace std;

// c++ 对象模型和this指针

// 成员变量和成员函数分开存储

class Person
{
    int m_a; //非静态成员变量 -> 属于对象上
    static int m_b; //静态成员变量  -> 不属于对象上
    void func(){}   //非静态成员函数   -> 不属于对象上
    static void func2(){} //静态成员函数   -> 不属于对象上
};

int Person::m_b = 10;

void test01()
{
    Person p;
    // 空对象占用内存空间：1 ->> c++编译器会给每个空对象分配一个字节空间，是为了区分空对象占内存的位置
    cout << "size of p = " << sizeof(p) << endl;
}

void test02()
{
    Person p;
    // 
    cout << "size of p = " << sizeof(p) << endl;    
}

int main()
{

    // test01();
    test02();
    return 0;
}

//结论：只有非静态成员变量属于类的对象上