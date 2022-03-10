#include<iostream>
using namespace std;

//三目运算符：
// 语法：表达式1 ？ 表达式2 ：表达式3

int main(){
    int a = 10;
    int b = 20;
    int c = 3;
    int d = 0;

    a > b ? c = a: c = b;
    cout << c << endl;
    d = (a > b ? a: b);
    cout << d << endl;

    (a > b ? a: b) = 100;
    cout << a << endl;
    cout << b << endl;
    //c++中三目运算返回的是变量，可以继续赋值

    return 0;
}