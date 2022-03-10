#include<iostream>
using namespace std;

// 前置递增，前置递减，后置递增，后置递减

int main(){
    int a = 10;
    ++a;
    cout << a << endl;

    int b = 10;
    b++;
    cout << b << endl;

    //区别：
    //前置递增，先让变量+1，然后进行表达式运算
    int a2 = 10;
    int b2 = ++a2 * 10;
    cout << a2 << endl;
    cout << b2 << endl;

    //后置递增，先进性表达收运算，后让变量加1
    int a3 = 10;
    int b3 = a3++ * 10;
    cout << a3 << endl;
    cout << b3 << endl;

    return 0;
}