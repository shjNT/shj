#include<iostream>
using namespace std;

//二维数组名

int main(){
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // 查看内存占用大小
    cout << sizeof(arr) << endl;
    cout << sizeof(arr[0]) << endl;
    cout << sizeof(arr[0][0]) << endl;

    // 首地址
    cout << (long)arr << endl;
    cout << (long)arr[1] << endl;
    cout << (long)&arr[1][0] << endl;
    return 0;
}