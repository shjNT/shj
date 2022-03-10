#include<iostream>
using namespace std;

//单行格式if语句： if(条件){满足执行的语句}

int main(){
    int score = 0;
    cout << "请输入分数:" << endl;
    cin >> score;
    cout << "输入的分数是: " << score << endl;

    if(score > 600){
        cout << "恭喜恭喜!!" << endl;
    }

    return 0;
}