#include<iostream>
using namespace std;

// 函数重载
// 作用：函数名可以相同，提高复用性

// 函数重载满足条件：
// ①同一作用域下；②函数名称相同；③函数参数类型不同或者个数不同或者顺序不同
// 注意：函数的返回值是不可以作为函数重载的条件

void func()
{
    cout << "func" << endl;
}

void func(int a)
{
    cout << "func " << a << endl;
}

double func(double a)
{
    cout << "func " << a << endl;
    return a;
}

double func(double a, int b)
{
    cout << "func " << a << endl;
    return a;
}

double func(int a, double b)
{
    cout << "func " << a << endl;
    return a;
}

int main(){

    // func();
    // func(10);
    // func(3.14);
    func(3, 3.14);
    func(3.14, 10);
    return 0;
}