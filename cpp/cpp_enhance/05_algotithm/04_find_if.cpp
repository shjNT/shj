#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// find_if(iterator beg, end, _Pred)

// 内置数据类型
class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end())
    {
        cout << "没找到" << endl;
    }
    else
    {
        cout << (*it) << endl;
    }
}

// 自定义数据类型
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

class Greater20
{
public:
    bool operator()(Person &p)
    {
        return p.m_age > 20;
    }
};

void test02()
{
    vector<Person> v;

    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p5("fff", 70);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p5);
    v.push_back(p3);
    v.push_back(p4);

    // 年龄>20
    vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
    if (it == v.end())
    {
        cout << "没找到" << endl;
    }
    else
    {
        cout << "找到: " << it->m_name << "  " << it-> m_age << endl;
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}