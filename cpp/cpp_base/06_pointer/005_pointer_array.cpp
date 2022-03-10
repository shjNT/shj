#include<iostream>
using namespace std;

// 指针和数组：利用指针访问数组中的元素

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << arr[0] << endl;

    int * p = arr;
    cout << *p << endl;
    p ++;
    cout << *p << endl;

    cout << "指针遍历数组" << endl;
    int * p2 = arr;
    for (int i=0; i< 10; i++){
        cout << *p2 << endl;
        p2++;
    }
    

    return 0;
}