#include<iostream>
using namespace std;

//乘法口诀表

int main(){

    for(int i = 1; i<10; i++){
        for (int j = 1; j <=i; j++){
            cout << j << "*" << i << "=" << j*i << '\t';
        }
        cout << endl;
    }

    return 0;
}