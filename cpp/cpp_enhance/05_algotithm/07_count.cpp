#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

// count(iteraot beg, end, value); -->> 返回int个数


// 内置数据类型
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(50);
    v.push_back(40);
    v.push_back(40);

    int num = count(v.begin(), v.end(), 40);
    cout << num << endl;
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

    bool operator==(const Person &p)    // 重载时参数要加const
    {
        if (this->m_age == p.m_age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_name;
    int m_age;
};

void test02()
{
    vector<Person> v;
    Person p1("sun", 18);
    Person p2("zhao", 18);
    Person p3("qian", 18);
    Person p4("li", 28);
    Person p5("wang", 48);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    Person p("zhuge", 18);

    int num = count(v.begin(), v.end(), p);
    cout << "和p年龄相同的人数: " << num << endl;
}


int main()
{
    // test01();
    test02();
    return 0;
}