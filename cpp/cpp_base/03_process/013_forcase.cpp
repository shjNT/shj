#include<iostream>
using namespace std;

//for case
//逢7过

int main(){
    int num = 1;
    for(int i = 1; i <= 100; i++){
        if(i % 7 == 0 || i % 10 == 7 || i / 10 == 7){
            cout << i << endl;
        }
    }
    return 0;
}