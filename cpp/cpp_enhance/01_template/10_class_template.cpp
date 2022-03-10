#include <iostream>
using namespace std;

// 类模板对象做函数参数
// 3中传入方式
// ①指定传入的类型 --直接显示对象的数据类型 (最常用)
// ②参数模板化 --将对象中的参数变为模板进行传递
// ③整体模板化 --将这个对象类型模板化进行传递

template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age)
    {
        this->m_name = name;
        this->m_age = age;
    }

    void show_person()
    {
        cout << "姓名:" << m_name << "\t年龄:" << m_age << endl;
    }
    T1 m_name;
    T2 m_age;
};

// ①指定传入类型
void print_person1(Person<string, int> &p)
{
    p.show_person();
}

void test01()
{
    Person<string, int> p("孙悟空", 555);
    print_person1(p);
}

// ②参数模板化
template <class T1, class T2>
void print_person2(Person<T1, T2> &p)
{
    p.show_person();
    cout << "T1的类型:" << typeid(T1).name() << endl;
    cout << "T2的类型:" << typeid(T2).name() << endl;
}
void test02()
{
    Person<string, int> p("猪八戒", 222);
    print_person2(p);
}

// ③整个类模板化
template<class T>
void print_person3(T &p)
{
    p.show_person();
    cout << "T的类型:" << typeid(T).name() << endl;
}

void test03()
{
    Person<string, int> p("沙和尚", 44);
    print_person3(p);
}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}