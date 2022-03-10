#include<iostream>
using namespace std;

// 值传递: 形参的变化不赢思想实参

// void表示无类型：即不需要返回值
void swap(int num1, int num2){

    cout << "交换前: " << num1 << "\t" << num2 << endl;

    int tmp = num1;
    num1 = num2;
    num2 = tmp;
    cout << "交换后: " << num1 << "\t" << num2 << endl;

}

int main(){

    int num1 = 1;
    int num2 = 2;

    swap(num1, num2);

    cout << num1 << "  " << num2 << endl;

    return 0;
}