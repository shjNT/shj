#include <iostream>
using namespace std;

// 类模板中成员函数的创建时机
// 普通类中的成员函数一开始就可以创建；类模板中的成员函数在调用时才创建

class Person1
{
public:
    void show_person1()
    {
        cout << "Person1" << endl;
    }
};

class Person2
{
public:
    void show_person2()
    {
        cout << "Person2" << endl;
    }
};

template <class T>
class MyClass
{
public:
    T obj;

    // 类模板中的成员函数; 
    void fun1()
    {
        obj.show_person1();
    }

    void fun2()
    {
        obj.show_person2();
    }
};

void test01()
{
    MyClass<Person1> m;
    m.fun1();

    MyClass<Person2> m2;
    m2.fun2();
}

int main()
{
    test01();
    return 0;
}


// 结论：类模板中的成员函数在调用的时候才创建出来