#include<iostream>
using namespace std;

// const修饰指针
/*
1. const修饰指针 --常量指针
2. const修饰常量 --指针常量
3. const既修饰指针，又修饰常量
*/

int main(){
    int a =10;
    int b =20;

    // 1.常量指针：指针的指向可以修改，但指针指向的值不可以改
    const int * p = &a;
    cout << p << endl;
    cout << *p << endl;
    p = &b;
    cout << p << endl;
    cout << *p << endl;

    // 2.指针常量：指针的指向不可以修改，但指针指向的值可以改
    int * const p1 = &a; 
    *p1 = 44;
    cout << *p1 << endl;

    // 3.都修饰: 都不能改
    const int * const p2 = & a;
    cout << * p2 << endl;
    // *p2 = 3;
    // p2 = &b;

    return 0;
}