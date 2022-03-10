#include<iostream>
using namespace std;

// 引用的本质: 指针常量

void func(int& ref)
{
    ref =100;      //转换为 *ref = 100
}


int main(){
    int a = 10;

    int &ref = a;   // 自动转换为 int* const ref = &a; 指针常量是指针的指向不可改，说明为什么引用不可更改
    ref = 20;   //内部发现ref是引用，自动转换为 *ref = 10

    cout << a << endl;
    cout << ref << endl;

    func(a);
    cout << a << endl;
    cout << ref << endl;
    return 0;
}