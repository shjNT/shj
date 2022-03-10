#include<iostream>
using namespace std;

// 普通函数与函数模板的区别

// 1. 普通函数调用可以发生隐式类型转换
// 2. 函数模板用自动类型推导，不可以发生隐式类型转换
// 3. 函数模板用显式指定类型，可以发生隐式类型转换

int my_add01(int a, int b)
{
    return a+b;
}

template <typename T>
T my_add02(T a, T b)
{
    return a+b;
}

void test01()
{
    int a = 10;
    int b = 30;
    char c = 'c';
    cout << my_add01(a, c) << endl;

    // 自动类型推导
    cout << my_add01(a, b) << endl;
    cout << my_add01(a, c) << endl;

}

int main()
{
    test01();
    return 0;
}