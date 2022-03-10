#include<iostream>
using namespace std;

// 普通函数与函数模板的调用规则
// ①优先调用普通函数
// ②可通过空模板参数强制调用函数模板
// ③函数模板也可以发生重载
// ④若函数模板可以产生更好的匹配结果，优先调用函数模板

void my_print(int a, int b)
{
    cout << a << b << endl;
    cout << "调用的是普通函数" << endl;
}

template <typename T>
void my_print(T a, T b)
{
    cout << a << b << endl;
    cout << "调用的是函数模板" << endl;
}

template <typename T>
void my_print(T a, T b, T c)
{
    cout << a << b<< c << endl;
    cout << "调用的是重载函数模板" << endl;
}

void test01()
{   
    // int a = 10;
    // int b = 30;
    // my_print(a, b);

    // 通过空模板参数列表，强制调用函数模板
    // my_print<>(a, b);
    // my_print<>(a, b, 1);

    //如果函数模板产生更好的匹配，优先调用函数模板
    char c1 = 'a';
    char c2 = 'b';
    my_print(c1, c2);
}

int main()
{
    test01();
    return 0;
}