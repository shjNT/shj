#include<iostream>
using namespace std;

// 语法: char ch = 'a';

int main(){

    // 1.创建
    char ch = 'a';
    cout << ch << endl;
    cout << sizeof(ch) << endl;

    //2.常见错误
    // char ch2 = "a";  要用单引号
    // char ch3 = 'abc'; 只能放一个字母

    //3，对应的ASCII编码
    cout << int(ch) << endl;
    cout << int('A') << endl;

    return 0;
}