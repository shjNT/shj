#include<iostream>
using namespace std;

//1.单精度float （4字节， 7个有效数字）

//2.双精度double  （8字节， 15~16个有效数字）

// 默认输出小数6位有效数字，额外显示需要配置

int main(){

    float f1 = 3.1415926f;   //加f不用从double转化成float
    cout << sizeof(f1) << endl;
    cout << f1 << endl;

    double d1 = 3.1415926;  
    cout << d1 << endl;
    cout << sizeof(d1) << endl;


    //科学记数法
    float f2 = 3e2; //3*10^2
    cout << f2 << endl;
    float f3 = 3e-2; //3*0.1^2
    cout << f3 << endl;

    return 0;
}