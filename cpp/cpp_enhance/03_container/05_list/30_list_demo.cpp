#include <iostream>
using namespace std;
#include <list>

// 排序案例

class Person
{
public:
    Person(string name, int age, int height)
    {
        this->m_name = name;
        this->m_age = age;
        this->m_height = height;
    }
    string m_name;
    int m_age;
    int m_height;
};


// 指定排序规则
bool compare_person(Person &p1, Person &p2)
{
    // 按年龄升序
    if(p1.m_age == p2.m_age)
    {
        // 身高降序
        return p1.m_height > p2.m_height;
    }
    return p1.m_age < p2.m_age;
}


void test01()
{
    list<Person> lp;

    Person p1("zhao", 35, 175);
    Person p2("qian", 45, 180);
    Person p3("sun", 40, 170);
    Person p4("li", 25, 190);
    Person p5("zhou", 35, 160);
    Person p6("wu", 35, 200);

    lp.push_back(p1);
    lp.push_back(p2);
    lp.push_back(p3);
    lp.push_back(p4);
    lp.push_back(p5);
    lp.push_back(p6);

    for(list<Person>::iterator it=lp.begin(); it !=lp.end(); it++)
    {
        cout << "姓名: " << (*it).m_name << "\t年龄: " << (*it).m_age << "\t身高: " << (*it).m_height << endl; 
    }

    // 排序
    lp.sort(compare_person);
    cout << "=========排序后========" << endl;
    for(list<Person>::iterator it=lp.begin(); it !=lp.end(); it++)
    {
        cout << "姓名: " << (*it).m_name << "\t年龄: " << (*it).m_age << "\t身高: " << (*it).m_height << endl; 
    }
}

int main()
{
    test01();
    return 0;
}