#include<iostream>
using namespace std;

// 结构体中嵌套结构体

struct Student
{
    string name;
    int age;
    int score;
};

struct Teacher
{
    int id;
    string name;
    int age;
    struct Student stu; // 必须给结构体变量，而不是定义的结构体
};

int main(){
    Teacher t;
    t.id = 10;
    t.name = "sun";
    t.age = 28;
    t.stu.name = "xiaosun";
    t.stu.age = 18;
    t.stu.score = 100;

    cout << t.name << endl;
    cout << t.stu.name << endl;

    return 0;
}