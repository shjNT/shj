#include<iostream>
using namespace std;

// 堆区
int * func()
{
    // 利用new关键字 -> 将数据开辟到堆区 -> 返回的是堆区地址
    int * p = new int(10);  // 指针本质也是局部变量，放在栈区，指针保存的数据放在堆区
    return p;
}

int main(){

    int * p = func();
    cout << *p << endl;
    cout << *p << endl;

    return 0;
}