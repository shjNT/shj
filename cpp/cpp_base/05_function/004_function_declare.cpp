#include<iostream>
using namespace std;

// 函数声明:告诉编译器函数名称及如何调用函数


// 函数声明：提前告诉编译器函数存在
int compare(int a, int b);

int main(){
    int a = 10;
    int b = 90;
    cout << compare(a, b) << endl;
    return 0;
}


int compare(int a, int b){
    return a > b ? a: b;
}