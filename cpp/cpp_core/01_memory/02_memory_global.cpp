#include<iostream>
using namespace std;

// 全局区
//全局变量、静态变量、常量


// 全局变量
int a_g = 10;
int b_g = 10;

// const 修饰的全局变量
const int c_g_a = 10;
const int c_g_b = 10;

int main(){

    // 普通常量 --> 函数体内
    int a = 10;
    int b = 10;

    cout << (long)&a << endl;
    cout << (long)&b << endl;

    cout << "全局变量a的地址:" << (long)&a_g << endl;
    cout << "全局变量b的地址:" << (long)&b_g << endl;

    // 静态变量: 在普通变量前加static
    static int s_a = 10;
    static int s_b = 10;
    cout << "静态变量a的地址:" << (long)&s_a << endl;
    cout << "静态变量b的地址:" << (long)&s_b << endl;

    // 常量(字符串常量和const修饰的全局变量)
    // 字符串常量
    cout << "字符串常量的地址" << (long)&"hello world" << endl;

    // const修饰的变量
    // const修饰的全局变量
    cout << "const修饰的全局变量a: " << (long)&c_g_a << endl;
    cout << "const修饰的全局变量b: " << (long)&c_g_b << endl;
    // const修饰的局部变量
    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "const修饰的局部变量a: " << (long)&c_l_a << endl;
    cout << "const修饰的局部变量b: " << (long)&c_l_b << endl;

    return 0;
}