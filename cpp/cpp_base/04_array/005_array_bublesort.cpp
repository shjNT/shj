#include<iostream>
using namespace std;

// 冒泡排序(升序)

int main(){

    int arr[9] = {4, 2, 8, 0, 5, 7, 1, 3, 9};
    for(int i =0; i < 9; i ++){
        cout << arr[i] << '\t';
    } cout << endl;

    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9 -i -1; j++){
            if(arr[j] > arr[j + 1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }

        }
    }

    
    for(int i =0; i < 9; i ++){
        cout << arr[i] << '\t';
    } cout << endl;
    return 0;
}