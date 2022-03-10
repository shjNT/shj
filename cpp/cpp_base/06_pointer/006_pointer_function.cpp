#include<iostream>
using namespace std;

// 利用指针作为函数的参数，可以修改实参的值


//值传递
void swap0(int a, int b){

    int tmp = a;
    a = b;
    b = tmp;
    cout << "swap0:" << endl;
    cout << a << "  " << b << endl;
}


// 地址传递
void swap1(int * p1, int * p2){

    int tmp = * p1;
    *p1 = *p2;
    *p2 = tmp;
    cout << "swap1:" << endl;
    cout << *p1 << "  " << *p2 << endl;
}

int main(){
    int a = 10;
    int b = 20;
    swap0(a, b);
    cout << "main:  "<< a << "  " << b << endl;

    // 地址传递可以改变实参
    swap1(&a, &b);
    cout << "main:  "<< a << "  " << b << endl;

    return 0;
}