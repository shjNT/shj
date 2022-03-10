#include<iostream>
using namespace std;

// 常量引用
// 常量引用主要用来修饰形参，防止误操作(const 修饰形参，防止改变实参)

void show(const int & val)
{
    // val = 1000; 不能修改了
    cout << val << endl;
}


int main(){

    int a= 10;
    // int & ref = 10; // 引用必须是合法的内存空间
    const int & ref = 10; //编译器修改为： int trmp =10; const int & ref = tmp;
    // ref = 19; //只读，不可修改

    int b =100;
    show(b);
    cout << b << endl;

    return 0;
}