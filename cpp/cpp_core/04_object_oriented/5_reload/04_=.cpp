#include<iostream>
using namespace std;

// 赋值运算符重载

// c++编译器至少给一个类添加4个函数
/*
① 默认构造函数(无参，函数体为空)
② 默认析构函数(无参，函数体为空)
③ 默认拷贝构造函数，对属性进行值拷贝
④ 赋值运算符operator=，对属性进行值拷贝
*/

class Person
{
public:
    Person(int age)
    {
        m_age = new int(age);
    }
    ~Person()
    {
        if(m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
        }
    }
    // 重载赋值运算符
    Person& operator=(Person &p)
    {
        // m_age = p.m_age; //编译器提供的浅拷贝
        
        // 深拷贝流程：先判断是否在堆区有属性，若有先释放再拷贝
        if(m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
        }

        // 深拷贝
        m_age = new int(*p.m_age);
        return *this;

    }
    int *m_age;
};


void test01()
{
    Person p(18);
    Person p2(20);
    Person p3(30);

    //赋值操作
    p3 = p2 = p;
    cout << *p.m_age << endl;
    cout << *p2.m_age << endl;
    cout << *p3.m_age << endl;

}

int main()
{
    test01();
    int a =10;
    int b =10;
    int c =10;
    c = b = a;
    cout << a  << "\t" << b << "\t" << c <<endl;
    return 0;
}