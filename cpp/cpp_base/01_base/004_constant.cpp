#include<iostream>
using namespace std;
//常量不可修改

#define Day 7

int main(){
    //1.宏常量： define 常量名 常量值
    cout << "一周共有:" << Day << "天" << endl;

    //2.const修饰的变量 const 数据类型 常量名=常量值
    const int month = 12;
    
    cout << month << endl;    

    return 0;
}