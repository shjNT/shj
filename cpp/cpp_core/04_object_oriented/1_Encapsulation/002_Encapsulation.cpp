#include<iostream>
using namespace std;

// 学生类

class Student
{
public:

    //类中的属性和行为都称为成员
    //属性：成员属性、成员变量
    //行为：成员函数、成员方法
    int s_id;
    string s_name;

    // 通过行为给属性赋值
    void set_name(string name)
    {
        s_name = name;
    };

    void set_id(int id)
    {
        s_id = id;
    };
    

    void show(){
        cout << "姓名: " << s_name << "\t";
        cout << "学号: " << s_id<< endl;
    }
};

int main(){

    Student s1;
    s1.s_name = "sun";
    s1.s_id = 1;
    s1.show();

    Student s2;
    s2.set_id(22);
    s2.set_name("li");
    s2.show();

    return 0;
}