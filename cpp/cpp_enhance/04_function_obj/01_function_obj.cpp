#include <iostream>
using namespace std;

// 函数对象(仿函数)
/*
① 函数对象在使用时，可以想普通函数那样调用，可以有参数，可以有返回值
② 函数对象超出普通函数的概念，函数对象可以有自己的状态
③ 函数对象可以作为参数传递
*/

// ① 函数对象在使用时，可以想普通函数那样调用，可以有参数，可以有返回值
class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

void test01()
{
    MyAdd myadd;
    cout << myadd(10, 10) << endl;
}


// ② 函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
public:
    MyPrint()
    {
        this->count = 0;
    }

    void operator()(string test)
    {
        cout << test << endl;
        this -> count++;
    }

    int count; // 内部状态
};

void test02()
{
    MyPrint myprint;
    myprint("hello world");
    myprint("hello world");
    myprint("hello world");
    myprint("hello world");
    cout << "MyPrint调用次数: " << myprint.count << endl;
}


// ③ 函数对象可以作为参数传递

void do_print(MyPrint &m, string test)
{
    m(test);
}

void test03()
{
    MyPrint myprint;
    do_print(myprint, "hello c++");
}


int main()
{
    test01();
    test02();
    test03();
    return 0;
}