#include<iostream>
using namespace std;

// 引用注意事项
// ①引用必须初始化；②引用在初始化后不可更改


int main(){
    int a = 10;
    int &b = a;

    // 引用必须初始化；
    // int &c;

    // 引用在初始化后不可更改
    int d = 20;
    // int &b = d;
    b = d;
    cout << b << endl;


    return 0;
}