#include<iostream>
using namespace std;

// 函数重载注意事项
// ①引用作为重载条件； ②函数重载碰到函数默认参数


// ①引用作为重载条件t
void func(int &a)   // int &a = 10 不合法
{
    cout << "func(int &a)调用" << endl;
}

void func(const int &a)   // const int &a = 10 合法
{
    cout << "func(const int &a)调用" << endl;
}


//②函数重载碰到函数默认参数 -->> 函数重载尽量避免运用默认参数
void func2(int a, int b=10) 
{
    cout << "func2(int a, int b)调用" << endl;
}

void func2(int a) 
{
    cout << "func2(int a=10, int b)调用" << endl;
}

int main(){
    int a = 10;
    // func(a);
    // func(10);
    // func2(10);
    return 0;
}