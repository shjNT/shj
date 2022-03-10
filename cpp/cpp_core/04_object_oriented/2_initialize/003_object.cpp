#include<iostream>
using namespace std;

// 拷贝构造函数调用时机
/*
① 使用一个已经创建完毕的对象初始化一个新对象
② 值传递方式给函数参数传值
③ 以值方式返回局部对象
*/

class Person
{
public:
    Person()
    {
        cout << "默认构造" << endl;
    }

    Person(int a)
    {
        age = a;
        cout << "有参构造" << endl;
    }

    Person(const Person & p)
    {
        age = p.age;
        cout << "拷贝构造" << endl;
    }

    ~Person()
    {
        cout << "析构函数" << endl;
    }

    int age;
};


// ① 使用一个已经创建完毕的对象初始化一个新对象
void test01()
{
    Person p1(20);
    Person p2(p1);
    cout << p2.age << endl;
}


// ② 值传递方式给函数参数传值
// void do_work(Person p)
// {
// }
// void test02()
// {
//     Person p;
//     do_work(p);

// }

// ③ 以值方式返回局部对象

Person do_work2()
{
    Person p1;
    cout << (long*)&p1 << endl;
    return p1;
}
void test03()
{
    Person p = do_work2();
    cout << (long*)&p << endl;
}

int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}