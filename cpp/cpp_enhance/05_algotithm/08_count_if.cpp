#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// count_if(iterator beg, end, _Pred)

// 内置数据类型
class Greater20
{
public:
    bool operator()(int val)
    {
        return val > 20;
    }
};

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(30);

    int num = count_if(v.begin(), v.end(), Greater20());
    cout << "大于20的元素个数: " << num << endl;
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

class AgeGreater20
{
    public:
    bool operator()(const Person &p)
    {
        if(p.m_age>20)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void test02()
{
    vector<Person> v;

    Person p1("zhao", 18);
    Person p2("qian", 28);
    Person p3("sun", 18);
    Person p4("li", 48);
    Person p5("wang", 28);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // 大于20岁
    int num = count_if(v.begin(), v.end(), AgeGreater20());
    cout << "年龄大于20的人数" << num << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}