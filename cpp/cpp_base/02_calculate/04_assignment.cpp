#include<iostream>
using namespace std;

// 赋值

int main(){
    int a = 10;
    a = 20;

    cout << a << endl;

    a += 20;
    cout << a << endl;

    a -= 2;
    cout << a << endl;

    a = 10;
    a *= 2;
    cout << a << endl;

    a /= 4;
    cout << a << endl;

    a %= 2;
    cout << a << endl;

    return 0;
}