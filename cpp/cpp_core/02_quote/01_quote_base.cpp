#include<iostream>
using namespace std;

// 引用的基本使用 -- 取别名
// 语法：数据类型 &别名 = 原名

int main(){
    int a = 10;
    int &b = a;
    cout << b << endl;
    b = 20;
    cout << a << endl;

    return 0;
}