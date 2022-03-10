#include <iostream>
using namespace std;
#include <set>

// set排序 -> 自定义数据类型

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

class ComparePerson
{
    public:
    bool operator()(const Person &p1, const Person &p2)
    {
        // 按照年龄降序
        return p1.m_age > p2.m_age;
    }
};

void test01()
{
    // 自定义数据类型需指定排序规则
    set<Person, ComparePerson> s;

    Person p1("liu", 24);
    Person p2("guan", 28);
    Person p3("zhang", 25);
    Person p4("zhao", 21);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for(set<Person, ComparePerson>::iterator it = s.begin(); it !=s.end(); it++)
    {
        cout << "姓名: " << (*it).m_name << "\t年龄: " << (*it).m_age << endl;
    }
}

int main()
{
    test01();
    return 0;
}