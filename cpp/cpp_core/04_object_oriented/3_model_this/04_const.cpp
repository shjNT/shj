#include<iostream>
using namespace std;

// const修饰成员函数

// 常函数： ①const修饰的成员函数；②常函数内不可修改成员属性；③成员属性声明若加mutable，常函数中可修改

// 常对象： ①const修饰声明的对象；②常对象只能调用常函数


class Person
{
public:
    // this指针的本质：指针常量(指针的指向不可修改) 相当于 Person * const this
    void show() const // 相当于 const Person * const this(指向和值都不能改)
    {
        // this -> m_a = 100;
        this -> m_b = 100;

    }

    int m_a;
    mutable int m_b; //常函数中可修改
};

void test01()
{
    Person p;
    p.show();
}

void test02()
{
    // const Person p; //常对象
    // p1.m_a = 100;

}


int main()
{

    return 0;
}