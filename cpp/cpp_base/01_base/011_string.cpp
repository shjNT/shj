#include<iostream>
using namespace std;



// 字符串


int main(){
    // 1.C风格: （注意①变量加中括号；②双引号）
    char str[] = "hello world";
    cout << str << endl;

    // 2.C++风格：
    string str2 = "hello world2";    // #include<string> 
    cout << str2 << endl;  
    return 0;
}