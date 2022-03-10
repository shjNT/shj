#include<iostream>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

// 值传递
void stu_info(Student s){
    s.name = "zhao";
    cout << "值传递:[" << s.name << "\t" << s.age << "\t" << s.score  << "]" << endl;
};

// 地址传递
void stu_info1(Student * p){
    p->name = "qian";
    cout << "地址传递:[" << p->name << "\t" << p->age << "\t" << p->score  << "]" << endl;
};


int main(){

    Student s = {"sun", 20, 99};
    cout << "main:[" << s.name << "\t" << s.age << "\t" << s.score  << "]" << endl;

    stu_info(s);
    cout << "main1:[" << s.name << "\t" << s.age << "\t" << s.score  << "]" << endl;

    stu_info1(&s);
    cout << "main2:[" << s.name << "\t" << s.age << "\t" << s.score  << "]" << endl;
    return 0;
}