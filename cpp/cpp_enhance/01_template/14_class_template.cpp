#include <iostream>
using namespace std;

// 类模板与友元


// 全局函数 类外实现
template<class T1, class T2>
class Person;

template<class T1, class T2>
void print_person2(Person<T1, T2> p)
{
    cout << "姓名:" << p.m_name << "\t年龄:" << p.m_age << endl;
}



template<class T1, class T2>
class Person
{

    // 全局函数 类内实现
    friend void print_person(Person<T1, T2> p)
    {
        cout << "姓名:" << p.m_name << "\t年龄:" << p.m_age << endl;
    }

    // 全局函数 类外实现--- 加空模板参数列表
    friend void print_person2<>(Person<T1, T2> p);
   

public:
    Person(T1 name, T2 age)
    {
        this->m_name = name;
        this->m_age = age;
    }

private:
    T1 m_name;
    T2 m_age;
};




// 全局函数类内实现测试
void test01()
{
    Person<string, int> p("sun", 18);
    print_person(p);
}

// 全局函数类外实现测试
void test02()
{
    Person<string, int> p("sun", 18);
    print_person2(p);
}

int main()
{
    // test01();
    test02();
    return 0;
}


// 建议：全局函数类内实现推荐