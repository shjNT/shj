#include<iostream>
using namespace std;

//swith
//语法：
/*
switch(表达式){
    case 结果1：执行语句；break;
    case 结果1：执行语句；break;
    ...
    default: 执行语句；break；
}

缺点：表达式只能是整形和字符型
*/

int main(){

    int score = 0;
    cout << "请评分:" << endl;
    cin >> score;
    cout << "您打的分数是:" <<  score << endl;

    switch (score)
    {
    case 10:
        cout << "经典电影" << endl;
        break;
    
    case 9:
        cout << "好电影" << endl;
        break;
    
    case 8:
        cout << "好" << endl;
        break;

     case 7:
        cout << "还行" << endl;
        break;

    case 6:
        cout << "一般" << endl;
        break;
    
    default:
        cout << "烂片" << endl;
        break;
    }

    return 0;
}