#include <iostream>
using namespace std;

// 类模板和函数模板的区别
// ①类模板中没有自动类型推导的使用方式
// ②类模板在模板参数列表中可以有默认参数

template <class name_type, class age_type=int>  //这就是模板参数列表
class Person
{
public:
    Person(name_type name, age_type age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    void show_info()
    {
        cout << "name: " << this->m_name << "\tage: " << this->m_age << endl;
    }

    name_type m_name;
    age_type m_age;
};

void test01()
{
    // Person p1("sun", 100);   // 无法自动类型推导
    Person<string, int> p1("sun", 100);     //只能用显示指定类型
    p1.show_info();
}

void test02()
{
    Person<string> p2("sun", 100);     //只能用显示指定类型
    p2.show_info();
}

int main()
{
    test01();
    test02();
    return 0;
}