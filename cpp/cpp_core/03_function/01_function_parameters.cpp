#include<iostream>
using namespace std;

// 函数的默认参数
// 形参可以有默认值

int func(int a, int b=10, int c=20)
{
    return a+b+c;
}
// 注意
// ① 若某个位置有默认值，之后都得有
// ② 若函数声明有默认参数，函数实现就不能有默认参数(声明和实现只能有一个有默认参数)
int func2(int a=10, int b=10);

int func2(int a, int b)
{
    return a+b;
}


int main(){
    // int res = func(10, 40);
    int res = func2();
    cout << res << endl;
    return 0;
}