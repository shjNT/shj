#include<iostream>
using namespace std;

// 结构体指针: 利用操作符 -> 可以通过结构体指针访问结构体属性

struct Student
{
    string name;
    int age;
    int score;
};

int main(){

    Student s1 = {"sun", 18, 100};

    //指针
    Student * p = & s1;

    cout << p->age << "\t" << p->name << "\t" << p->score << endl;
    cout << p << endl;
    return 0;
}