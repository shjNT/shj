#include<iostream>
using namespace std;

struct Hero
{
    string name;
    int age;
    string gender;
};


void buble_sort(Hero h_arr[], int len){
    for(int i=0; i<len; i++){
        for(int j=0; j<len-i-1; j++){
            if(h_arr[j].age > h_arr[j+1].age){
                Hero tmp = h_arr[j];
                h_arr[j] = h_arr[j+1];
                h_arr[j+1] = tmp;
            }
        }
    }
    cout << "after sort:" << endl;
    for(int i=0; i<len; i++){
        cout << h_arr[i].name << "\t" << h_arr[i].age << "\t" << h_arr[i].gender<< endl;
    }
};


int main(){

    // 结构体变量数组
    Hero h_arr[5] = 
    {
        {"zhao", 23, "man"},
        {"qian", 22, "man"}, 
        {"sun", 20, "man"},
        {"li", 21, "man"},
        {"zhou", 19, "woman"}
    };

    int len = sizeof(h_arr) / sizeof(h_arr[0]);
    for(int i=0; i<len; i++){
        cout << h_arr[i].name << "\t" << h_arr[i].age << "\t" << h_arr[i].gender<< endl;
    }

    // 冒泡排序
    buble_sort(h_arr, len);

    // for(int i=0; i<len; i++){
    //     cout << h_arr[i].name << "\t" << h_arr[i].age << "\t" << h_arr[i].gender<< endl;
    // }


    return 0;
}