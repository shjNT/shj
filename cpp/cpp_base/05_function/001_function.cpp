#include<iostream>
using namespace std;

//定义
/*
返回值类型 函数名 (参数列表)
{
    函数体语句；
    return表达式；
}
*/

int slove_sum(int num1, int num2)
{
    int sum = num1 + num2;
    return sum;
}

   
int main(){
    int num1;
    int num2;
    cout << "输入第一个数:" << endl;
    cin >> num1;
    cout << "输入第二个数:" << endl;
    cin >> num2;

    int res = slove_sum(num1, num2);
    cout << res << endl;
    return 0;
}