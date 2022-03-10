#include<iostream>
using namespace std;

// sizeof:数据类型占用大小(单位：字节)

int main(){
    int a = 10;
    long b = 10;
    cout << sizeof(short) << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
    cout << sizeof(long long) << endl;
    return 0;
}