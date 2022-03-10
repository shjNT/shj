#include<iostream>
using namespace std;

//continue:跳过本次循环中尚未执行的语句,执行下一次循环

int main(){

    for(int i=0; i<100; i++){
        if(i % 2 == 0){
            continue;
        }
        cout << i << endl;
        
    }

    return 0;
}