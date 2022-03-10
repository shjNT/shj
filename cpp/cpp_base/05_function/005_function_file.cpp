#include<iostream>
using namespace std;
#include "006_function_file.h"

// 函数的分文件编写
/*
1.创建后缀名为.h的头文件
2.创建后缀名为.cpp的源文件
3.在头文件中写函数的声明
4.在源文件中写函数的定义
*/


// //声明
// void swap(int a, int b);

// 定义

// void swap(int a, int b){

//     int tmp = a;
//     a = b;
//     b = tmp;
//     cout << "a:" << a << "\t" << "b:" << b << endl;
//  }
int main(){

    swap(3, 4);

    return 0;
}