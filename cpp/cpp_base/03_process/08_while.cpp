#include<iostream>
using namespace std;

//while
//语法： while(循环条件){循环语句}

int main(){
    int i = 0;
    while(i<10){
        cout << i << endl;
        i ++;
        if(i > 5){
            break;
        }
    }


    return 0;
}