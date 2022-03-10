#include<iostream>
using namespace std;

// 堆区：new
// 1.new语法：new 数据类型
int * func()
{
    // 在堆区创建整形数据 >> 返回改数据类型的指针
    int * p = new int(10);
    return p;
}

void test01()
{
    int * p = func();
    cout << *p << endl;
    cout << *p << endl;
    // 释放堆区数据 delete
    delete p;
    cout << *p << endl; // ?
}

// 堆区创建整形数组
void test02()
{
    int* arr = new int[10];
    for(int i=0; i< 10; i++){
        arr[i] = i+100;
    }
    for(int i=0; i< 10; i++){
        cout << arr[i] << endl;
    }
    delete [] arr;
    cout << arr[0] << endl;
}


int main(){
    test01();
    // test02();
    return 0;
}