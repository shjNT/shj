#include<iostream>
using namespace std;

// 一维数组
/*
定义语法：
① 数据类型 数组名[ 数组长度 ];
② 数据类型 数组名[ 数组长度 ] = {值1，值2, ...};
③ 数据类型 数组名[ ] = {值1，值2, ...};
*/



int main(){

    //① 不赋值的位置为0
    // int score[10];
    // score[3] = 90;
    // for(int i=0; i< 10; i++){
    //     cout << score[i] << endl;
    // }

    //② 不赋值的位置为0
    // int score[10] = {1, 2, 3};
    // score[3] = 90;
    // for(int i=0; i< 10; i++){
    //     cout << score[i] << endl;
    // }
    // return 0;

    //③ 
    int score[] = {3, 4, 5};
    // score[100] = 90;
    for(int i=0; i< 3; i++){
        cout << score[i] << endl;
    }
}