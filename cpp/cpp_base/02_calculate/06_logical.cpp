#include<iostream>
using namespace std;

//逻辑运算符 !  &&  ||

int main(){
    int a = 10;
    cout << !a << endl;
    cout << !!a << endl;

    int b = 0;
    int c = 0;

    cout << (a && b) << endl;
    cout << (a || c) << endl;

    return 0;
}