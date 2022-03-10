#include<iostream>
using namespace std;

// 函数模板的注意事项
// ①自动类型推导必须推导出一致的数据类型T,才可使用
// ②模板必须确定出T的数据类型，才可使用


template<typename T>    //typename可以用class，没有区别
void my_swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void func()
{
    cout << "func调用" << endl;
}


void test01()
{
    int a = 10;
    int b = 30;
    // char c = 'd';
    my_swap(a, b);
    // my_swap(a, c);   // 推导不出一致的数据类型
    cout << a << "\t" << b << endl;

    // func(); //没有明确T
    func<int>(); // 只有用显示指明T
}

int main()
{
    test01();
    return 0;
}