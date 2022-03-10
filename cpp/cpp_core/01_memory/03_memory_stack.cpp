#include<iostream>
using namespace std;

// 栈区: 局部变量和形参

// 栈区数据由编译器管理开辟和释放

// 注意:不要返回局部变量的地址
int * fun(int b)
{
    cout << b << endl;
    int a = 10; //局部变量 存放在栈区，栈区的数据在函数执行完后自动释放
    return &a; //返回局部变量的地址
}

int main(){
    int * p = fun(1);
    cout << *p << endl; //编译器保留
    cout << *p << endl; //编译器不再保留
    return 0;
}