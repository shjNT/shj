#include<iostream>
using namespace std;

//int:
/*
1.short(短整型)         2字节
2.int(整形)             4字节
3.long(长整型)           windows4字节；linux4字节(32b),8字节(64b)
4.long long(长长整形)    8字节
*/

int main(){

    short num1 = 3278;

    //一般int
    int num2 = 32769;

    long num3 = 32769;

    long long num4 = 32769;

    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    cout << num4 << endl;
    return 0;
}
