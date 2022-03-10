#include <iostream>
using namespace std;

// 模板的局限性

class Person
{
public:
    Person(string name, int age)
    {
        m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};

template <typename T>
bool my_compare(T &a, T &b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 利用具体化Person的版本实现代码，具体化优先调用
template<> bool my_compare(Person &p1, Person &p2)
{
    if (p1.m_name == p2.m_name && p1.m_age == p2.m_age)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void test01()
{
    int a = 10;
    int b = 30;
    bool ret = my_compare(a, b);
    cout << ret << endl;
}

void test02()
{
    Person p1("sun", 18);
    Person p2("liu", 20);
    bool ret = my_compare(p1, p2);
    cout << ret << endl;
}


int main()
{
    test01();
    test02();
    return 0;
}