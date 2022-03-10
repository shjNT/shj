#include<iostream>
using namespace std;

//逆置数列

int main(){

    int arr[5] = {1, 3, 4, 5, 4};

    int start = 0; //起始元素下标
    int end = sizeof(arr) / sizeof(arr[0]) -1; //末尾元素下标
    int tmp = 0;

    while(start < end){
        tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;

        start ++;
        end --;
    }

    for(int i = 0; i< 5; i++){
        cout << arr[i] << endl;
    }

    return 0;
}