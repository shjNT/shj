#include<iostream>
using namespace std;

// 结构体：属于用户自定义的数据类型，允许用户存储不同的数据类型

// 语法：struct 结构体名 {结构体成员列表}

// 自定义数据类型
struct Student
{
    string name;
    int age;
    int score;
}s3;




int main(){
    // 创建结构体变量（struct可以省略）
    // ①struct Student s1;
    Student s1;
    s1.name = "sun";
    s1.age = 18;
    s1.score = 100;

    cout << s1.name << "\t" << s1.age <<  "\t" << s1.score << endl;



    // ②struct Student s2 = {'sun', 24, 180};
    struct Student s2 = {"wang", 21, 80};
    cout << s2.name << "\t" << s2.age <<  "\t" << s2.score << endl;

    // ③定义结构体时顺带创建结构体变量
    s3.name = "li";
    s3.age = 24;
    s3.score = 10;
    cout << s3.name << "\t" << s3.age <<  "\t" << s3.score << endl;

    return 0;
}