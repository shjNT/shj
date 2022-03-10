#include<iostream>
using namespace std;

//if嵌套

int main(){
    int score = 0;
    cout << "请输入高考分数" << endl;
    cin >> score;
    cout << "您输入的分数是:" << endl;

    if(score>=600){
        if(score > 700){
            cout << "考上北大，牛逼!!" << endl;
        }
        else if(score > 650){
            cout << "考上清华， 666!!" << endl;
        }
        else{
            cout << "考上人大，6!" << endl;
        }}
    else if(score >= 500){
        cout << "考上二本，恭喜" << endl;
    }
    else if(score >= 400){
        cout << "考上三本，还行" << endl;
    }
    else{
        cout << "没考上，垃圾" << endl;
    }

    return 0;
}