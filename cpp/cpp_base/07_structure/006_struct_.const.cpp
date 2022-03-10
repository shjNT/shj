#include<iostream>
using namespace std;

//const

struct Student
{
    string name;
    int age;
    int score;
};


// 将形参改为指针,可以减少内存空间，并且不会复制新的副本
void stu_info(const Student * s){

    // s -> name = "zhao"; const修饰后，不允许修改操作
    cout << s->name << "\t" << s->age << "\t" << s->score << endl;
};

int main(){

    Student s = {"sun", 18, 99};

    stu_info(&s);
    cout << s.name << "\t" << s.age << "\t" << s.score << endl;

    return 0;
}