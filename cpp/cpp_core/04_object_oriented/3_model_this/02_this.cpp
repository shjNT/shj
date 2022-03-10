#include<iostream>
using namespace std;

// this指针

// 每个非静态成员函数只诞生一份函数实例，也就是说多个同类型对象会共用一块代码，那么如何区分？

// 特殊的对象指针(this指针)：this指针指向被调用的成员函数所属的对象

// this指针用途：①形参和成员变量同名，可用this区分；②非静态成员函数返回对象本身，可用return *this


class Person
{
public:
    Person(int age)
    {
        // this指针指向：被调用成员函数所属的对象
        this->age = age;
    }

    // 以引用的方式返回：一直返回的是该对象，而值返回会构造新的对象
    Person& person_add_age(Person &p)
    {
        this->age += p.age;
        // this指向p2,而*this指向p2对象本体
        return *this;
    }

    int age;
};

void test01()
{
    Person p1(18);
    cout << p1.age << endl;
}

void test02()
{
    Person p1(10);
    Person p2(10);
    p2.person_add_age(p1).person_add_age(p1).person_add_age(p1);
    cout << p2.age << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}