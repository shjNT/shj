#include <iostream>
using namespace std;

// c++中另一种编程思想：泛型编程，主要利用的技术为模板
// 模板：函数模板和类模板

// 函数模板
// 作用：建立一个通用函数，返回值和形参类型不具体指定，用一个虚拟的类型来代表
// 语法：template <typename T>


// 函数模板 -->> 将数据类型参数化
template <typename T>   //声明一个模板，告诉编译器后面代码中紧跟的T不要报错，T指代一个通用数据类型
void my_swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}


void test01()
{
    int a = 10;
    int b = 20;
    float c = 2.2;
    float d = 5.6;
    // 1.自动类型推导
    my_swap(a, b);
    cout << a << "\t" << b << endl;
    my_swap(c, d);
    cout << c << "\t" << d << endl;

    // 2.显示指定类型
    my_swap<int>(a, b);
    my_swap(a, b);
    cout << a << "\t" << b << endl;

}

int main()
{
    test01();
    return 0;
}