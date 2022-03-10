#include <iostream>
using namespace std;
#include <vector>

// vector存放自定义数据类型

class Person
{
public:
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};

void test01()
{
    vector<Person> v;
    Person p1("sun", 18);
    Person p2("zhao", 12);

    v.push_back(p1);
    v.push_back(p2);


    for(vector<Person>::iterator it = v.begin(); it !=v.end(); it++)
    {
        // *it 迭代器解引用出来的是person对象
        cout << "姓名: " << (*it).m_name << "\t年龄: " << (*it).m_age << endl;  
        // it当成指针
        cout << "姓名: " << it->m_name << "\t年龄: " << it->m_age << endl;  
    }
}

// 存放自定义类型指针
void test02()
{
    vector<Person *> v;
    Person p1("sun", 18);
    Person p2("zhao", 12);

    v.push_back(&p1);
    v.push_back(&p2);

    for(vector<Person*>::iterator it = v.begin(); it !=v.end(); it++)
    {
        // *it 迭代器解引用出来的是person对象的指针
        cout << "姓名: " << (*it)->m_name << "\t年龄: " << (*it)->m_age << endl;  
    }
}

int main()
{
    test01();
    test02();
    return 0;
}