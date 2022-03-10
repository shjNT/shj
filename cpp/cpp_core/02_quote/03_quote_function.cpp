#include<iostream>
using namespace std;

// 引用做函数的参数
// 优点：让形参修饰实参，代替指针


//1.值传递
void swap01(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//2.地址传递
void swap02(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//3.引用传递
void swap03(int &a, int &b)
{
   int  tmp = a;
    a = b;
    b = tmp;
}


int main(){
    int a = 10;
    int b = 20;
    // swap01(a, b);
    // swap02(&a, &b);
    swap03(a, b);

    cout << "a: " << a << "\t" << "b: "<< b << endl;
    return 0;
}