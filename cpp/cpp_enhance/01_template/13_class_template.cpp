#include<iostream>
using namespace std;

// ①直接包含源码
// #include "person.cpp"

// ②将 .h和 .cpp中的内容写到一起，后缀改为 .hpp文件
#include "person.hpp"

// 类模板中的分文件编写


// template<class T1, class T2>
// class Person
// {
// public:
//     Person(T1 name, T2 age);
//     void show_person();
//     T1 m_name;
//     T2 m_age;
// };

// template<class T1, class T2>
// Person<T1, T2>::Person(T1 name, T2 age)
// {
//     this->m_name = name;
//     this->m_age = age;
// }

// template<class T1, class T2>
// void Person<T1, T2>::show_person()
// {
//     cout << "姓名:" << this->m_name << "\t年龄:" << this->m_age << endl;
// }


void test01()
{
    Person<string, int> p("sun", 18);
    p.show_person();
}

int main()
{
    test01();
    return 0;
}