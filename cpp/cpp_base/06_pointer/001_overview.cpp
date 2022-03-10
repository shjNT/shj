#include<iostream>
using namespace std;

//指针：可以通过指针间接访问内存

//定一指针： 数据类型 * 指针变量名


int main(){
    int a = 10;
    // 定义指针变量p
    int * p;
    // 让指针记录变量a的地址
    p = &a;

    cout << "a的地址:" << &a << endl;
    cout << p << endl;


    //使用指针：可以通过解引用的方式来找到指针指向的内存 -- *p
    cout << *p << endl;

    *p = 1000;
    cout << a << endl;
    cout << *p << endl;

    
    return 0;
}