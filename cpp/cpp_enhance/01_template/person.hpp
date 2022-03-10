#include<iostream>
#pragma once
using namespace std;

template<class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);
    void show_person();
    T1 m_name;
    T2 m_age;
};


template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_name = name;
    this->m_age = age;
}

template<class T1, class T2>
void Person<T1, T2>::show_person()
{
    cout << "姓名:" << this->m_name << "\t年龄:" << this->m_age << endl;
}