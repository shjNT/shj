#include<iostream>
using namespace std;

//break:跳出选择(switch)或循环结构

int main(){

    // cout << "选择游戏难度" << endl;
    // cout << "1.普通" << endl;
    // cout << "2.中等" << endl;
    // cout << "3.困难" << endl;

    // int select = 0;
    // cin >> select;
    
    // switch (select)
    // {
    // case 1:
    //     cout << "1.普通" << endl;
    //     break;
    // case 2:
    //     cout << "2.中等" << endl;
    //     break;
    // case 3:
    //     cout << "3.困难" << endl;
    //     break;
    
    // default:
    //     break;
    // } 

    // for(int i = 0; i<10; i++){
    //     cout << i << endl;
    //     if(i==5){
    //         break;
    //     }
    // }

    for(int i=0; i < 10; i++){
        for(int j=0; j < 10; j++){
            cout << "* "; 
            if (j == 4){
                break;
            }
        
        }
        cout << endl;
        if(i == 4){
            break;
        }
    }

    return 0;
}