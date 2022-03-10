#include<iostream>
using namespace std;

//do...while case
//水仙花数

int main(){
    int num = 100;

    do
    {
        int num1 = num % 10;    //个位
        int num2 = num / 10 % 10;   //十位
        int num3 = num / 100;   //百位

        if(num1*num1*num1 + num2*num2*num2 + num3*num3*num3 == num){
            cout << num << endl;
        }
        num++;
    } while (num < 1000);
    
    return 0;
}