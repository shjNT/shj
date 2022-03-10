#include<iostream>
using namespace std;

// 二维数组
// 定义方式：
/*
1. 数据类型 数组名[行数][列数];
2. 数据类型 数组名[行数][列数] = {{数据1， 数据2}， {数据3， 数据4}...};
3. 数据类型 数组名[行数][列数] = {数据1， 数据2，数据3， 数据4...};
4. 数据类型 数组名[][列数] = {数据1， 数据2，数据3， 数据4...};
*/

int main(){

    // 未赋值前为0
    int arr[2][3];
    for(int i =0; i<2; i++){
        for(int j=0; j<3; j++){
            cout << arr[i][j] << "\t";
        } cout << endl;
    } cout << endl;


    //建议
    int arr1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for(int i =0; i<2; i++){
        for(int j=0; j<3; j++){
            cout << arr1[i][j] << "\t";
        } cout << endl;
    } cout << endl;



    // 
    int arr2[3][2] = {1, 2, 3, 4, 5, 6};
    for(int i =0; i<3; i++){
        for(int j=0; j<2; j++){
            cout << arr2[i][j] << "\t";
        } cout << endl;
    } cout << endl;

    //
    int arr3[][4] = {2, 3, 4, 5, 7, 8, 99, 0};
    for(int i =0; i<2; i++){
        for(int j=0; j<4; j++){
            cout << arr3[i][j] << "\t";
        } cout << endl;
    } cout << endl;

    return 0;


}