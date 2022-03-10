#include<iostream>
using namespace std;

//多行if: if(条件){满足执行的}else{不满足执行的}；

int main(){

    int score = 0;
    cout << "请输入分数:" << endl;
    cin >> score;
    cout << "您输入的分数是:" << score << endl;

    if(score >= 600){
        cout << "恭喜恭喜!!!" << endl;
    }else{
        cout << "望继续努力。。" << endl;
    }

    return 0;
}