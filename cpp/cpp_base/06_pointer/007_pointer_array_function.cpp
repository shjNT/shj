#include<iostream>
using namespace std;

// 封装一个函数，利用冒泡排序，实现升序排序

void bublesort(int * arr, int len);
void printarr(int * arr, int len);

int main(){
    
    int arr[10] = {2, 4, 3, 1, 9, 0, 5, 7, 6, 8};
    int len = sizeof(arr) / sizeof(arr[0]);

    bublesort(arr, len);
    printarr(arr, len);

    return 0;
}

void bublesort(int * arr, int len){
    for(int i=0; i< len-1; i++){
        for(int j =0; j<len-1-i; j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= tmp;
            }            
        }
    }
}

void printarr(int * arr, int len){
    for(int i=0; i<len; i++){
        cout << arr[i] << endl;
    }
}