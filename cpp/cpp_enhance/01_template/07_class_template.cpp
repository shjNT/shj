#include <iostream>
using namespace std;

// 类模板
// 语法：template<class T>

template <class name_type, class age_type>
class Person
{
public:
    Person(name_type name, age_type age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    name_type m_name;
    age_type m_age;
};


void test01()
{
    Person<string, int> p1("sun", 18);
    cout << p1.m_name << "\t" << p1.m_age << endl;
}

int main()
{
    test01();

    return 0;
}