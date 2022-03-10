#include<iostream>
using namespace std;

//猜数字

int main(){
    
    //添加随机数种子，利用当前系统时间生成随机数
    srand((unsigned int)time(NULL));

    //系统生成随机数
    int num = rand() % 100 + 1;     //生成1~100的随机数
    cout << num << endl;

    int val = 0;

    while (true)
    {
        cin >> val;

        if(val > num){
            cout << "过大" << endl;
        }
        else if(val < num){
            cout << "过小" << endl;
        }
        else{
            cout << "猜对" << endl;
            break;
        }

    }
       

    return 0;
}