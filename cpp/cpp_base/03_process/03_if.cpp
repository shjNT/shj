#include<iostream>
using namespace std;

//多条件if
//语法： if(条件1){条件1满足执行的}else if(条件2){条件2满足执行的语句}。。。else{都不满足执行的}

int main(){
    int score = 0;
    cout << "请输入考试分数:" << endl;
    cin >> score;
    cout << "您输入的分数是: " << score << endl;

    if(score >= 600){
        cout << "考上一本，恭喜恭喜!!!" << endl;
    }
    else if(score >= 500){
        cout << "考上二本， 恭喜!" << endl;
    }
    else if(score >= 400){
        cout << "考上三本， 还行。" << endl;
    }
    else{
        cout << "没考上，垃圾" << endl;
    }
    return 0;
}