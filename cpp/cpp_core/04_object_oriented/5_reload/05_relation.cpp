#include<iostream>
using namespace std;

// 关系运算符重载 ：可让两个自定义类型进行对比操作

class Person
{
public:
    Person(string name, int age)
    {
        m_name = name;
        m_age = age;
    }

    // 重载 == 
    bool operator==(Person &p)
    {
        if(this->m_name == p.m_name && this->m_age == p.m_age)
        {
            return true;
        }
        return false;
    }

    // 重载 != 
    bool operator!=(Person &p)
    {
        if(this->m_name != p.m_name || this->m_age != p.m_age)
        {
            return true;
        }
        return false;
    }
    int m_age;
    string m_name;
};

void test01()
{
    Person p1("sun", 18);
    Person p2("sun", 18);

    if(p1 == p2)
    {
        cout << "p1和p2是相等的" << endl;
    }
    else{
        cout << "p1和p2是不相等的" << endl;   
    }
}

void test02()
{
    Person p1("sun", 18);
    Person p2("sun", 18);

    if(p1 != p2)
    {
        cout << "p1和p2是不相等的" << endl;
    }    else{
        cout << "p1和p2是相等的" << endl;   
    }
}

int main()
{
    test01();
    test02();
    return 0;
}