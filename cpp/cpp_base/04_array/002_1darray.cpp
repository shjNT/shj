#include<iostream>
using namespace std;

int main(){

    long arr1[6] = {1, 2, 3, 4, 5};
    cout << sizeof(arr1) << endl;
    cout << sizeof(arr1[0]) << endl;

    //数组首地址
    cout << arr1 << endl;   //16进制
    cout << (long)arr1 << endl;  //转为10进制

    //数组元素第一个元素地址
    cout << (long)&arr1[0] << endl; //加&

    cout << (long)&arr1[1] << endl;

    cout << (long)&arr1[1] - (long)&arr1[0]<< endl;

    //数组名是常量，不可赋值
    // arr1 = 100;

    return 0;
}