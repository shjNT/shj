#include<iostream>
using namespace std;

// 结构体数组:数组元素为结构体变量

// 语法： struct 结构体名 数组名[元素个数]={{}， {}， ...}

struct Student
{
    string name;
    int age;
    int score;
};


int main(){

    struct Student stu_arr[3] = 
    {
        {"sun", 18, 100},
        {"zhao", 21, 80},
        {"liu", 24, 89}
    };

    stu_arr[2].name = "wang";
    stu_arr[2].score = 0;

    for(int i=0; i< 3; i++){
        cout << stu_arr[i].name << "\t"
        << stu_arr[i].age << "\t"
        << stu_arr[i].score << endl;
    }
}