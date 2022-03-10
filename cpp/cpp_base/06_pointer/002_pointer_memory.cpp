#include<iostream>
using namespace std;

// 指针所占的内存空间: 64位8个字节；32位4个字节


int main(){

    int a = 10;
    int * p;
    p = &a;

    cout << sizeof(p) << endl;
    cout << sizeof(int *) << endl;
    cout << sizeof(long *) << endl;
    cout << sizeof(float *) << endl;
    cout << sizeof(double *) << endl;

    return 0;
}