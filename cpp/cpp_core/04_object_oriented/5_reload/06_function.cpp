#include<iostream>
using namespace std;

// 函数调用运算符()重载 -->> 仿函数

class MyPrint
{
public:
    // 重载函数调用运算符
    void operator()(string test)
    {
        cout << test << endl;
    }

};


void test01()
{
    MyPrint m1;
    m1("hello world");  //使用起来非常类似函数调用，因此称为仿函数 
}

// 仿函数非常灵活，没有固定写法
// 加法类
class MyAdd
{
public:
    int operator()(int a, int b)
    {
        return a+b;
    }
};

void test02()
{
    MyAdd ma;
    cout << ma(2, 4) << endl;

    // 匿名函数对象
    cout << MyAdd()(100, 200) << endl;

}
int main()
{
    // test01();
    test02();
    return 0;
}