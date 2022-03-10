#include<iostream>
using namespace std;

//if案例

int main(){
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    cout << "请输入a的重量:" << endl;
    cin >> num1;

    cout << "请输入b的重量:" << endl;
    cin >> num2;

    cout << "请输入c的重量:" << endl;
    cin >> num3;

    cout << "a的重量:" << num1 << endl;
    cout << "b的重量:" << num2 << endl;
    cout << "c的重量:" << num3 << endl;

    if(num1 >= num2){
        if(num1 > num3){
            cout << "a最重" << endl;
        }
        else{
            cout << "c最重" << endl;
        }
    }
    else{
        if(num2 > num3){
            cout << "b最重" << endl;
        }
        else{
            cout << "c最重" << endl;
        }

    }

    return 0;
}