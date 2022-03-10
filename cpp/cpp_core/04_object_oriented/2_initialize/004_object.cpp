#include<iostream>
using namespace std;

// 构造函数的调用规则
// 默认情况下，编译器至少给一个类添加3个函数：①默认无参构造函数；②默认析构函数；③默认拷贝构造函数(属性拷贝)

// 调用规则：
// ①若定义有参构造，则不提供无参构造，但提供拷贝构造
// ②若定义拷贝构造，则c++不提供其他构造

class Person
{
public:
    Person()
    {
        cout << "默认构造"  << endl;
    }

    Person(int a)
    {
        age = a;
        cout << "有参构造"  << endl;
    }

    Person(const Person & p)
    {
        age = p.age;
        cout << "拷贝构造" << endl;
    }

    ~Person()
    {
        cout << "析构"  << endl;
    }

    int age;
};

// void test01()
// {
//     Person p;
//     p.age = 18;

//     Person p2(p);
//     cout << p2.age << endl;
// }

// ①若定义有参构造，则不提供无参构造，但提供拷贝构造
// ②若定义拷贝构造，则c++不提供其他构造
void test02()
{
    Person p3(19);
    Person p4(p3);
    cout << p4.age << endl;
}


int main()
{
    // test01();
    test02();
    return 0;
}