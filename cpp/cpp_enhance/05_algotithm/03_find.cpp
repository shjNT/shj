// 常用查找算法
/*
① find 
② find_if
③ adjacent_find   --  查找相邻重复元素
④ binary_search  --  二分查找
⑤ cout
⑥ count_if   --   按条件统计元素个数
*/

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// find(iterator beg, end, value)

// 查找内置数据类型
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator it = find(v.begin(), v.end(), 5);
    if (it == v.end())
    {
        cout << "没找到" << endl;
    }
    else
    {
        cout << "找到: " << (*it) << endl;
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

    // 重载 == 让find底层知道如何对比person数据类型
    bool operator==(const Person &p)
    {
        if(this->m_name == p.m_name && this->m_age == p.m_age)
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
    vector<Person> v1;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    Person pp("ccc", 30);

    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);

    vector<Person>::iterator it = find(v1.begin(), v1.end(), pp);
    if(it == v1.end())
    {
        cout << "没有找到" << endl;
    }
    else
    {
        cout << "找到: " << (*it).m_name << (*it).m_age << endl;
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}