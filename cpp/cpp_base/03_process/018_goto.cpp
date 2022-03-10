#include<iostream>
using namespace std;

//goto:无条件跳转语句
//语法： goto 标记；

int main(){

    cout << "sunsunsun" << endl;
    goto A;
    cout << "1111" << endl;
    A:
    cout << "2222" << endl;

    return 0;
}