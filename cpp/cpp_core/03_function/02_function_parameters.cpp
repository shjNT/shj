#include<iostream>
using namespace std;

// 函数占位参数
// 函数的形参列表中可以有占位参数，用来占位，调用函数时必须填补该位置

// 占位参数也可有默认参数
void func(int a, int = 10)
{
    cout << "a: " << a << endl;
}

int main(){

    func(10);

    return 0;
}