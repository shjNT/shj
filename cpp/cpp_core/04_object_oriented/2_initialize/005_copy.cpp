#include<iostream>
using namespace std;

// 深拷贝和浅拷贝
// ①浅拷贝：简单的赋值操作； ②深拷贝：在堆区重新申请空间，进行拷贝操作

// 总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题；


class Person
{
public:
    Person()
    {
        cout << "默认构造" << endl;
    }

    Person(int age, int height)
    {
        m_age = age;
        m_height = new int(height);
        cout << "有参构造" << endl;
    }

    Person(const Person &p)
    {
        cout << "拷贝构造" << endl;
        m_age = p.m_age;
        // m_height = p.m_height; // 编译器的实现

        // 深拷贝
        m_height = new int (*p.m_height);
    }

    
    ~Person()
    {
        // 堆区开辟的数据释放 -->> 浅拷贝会导致堆区内存重复释放
        if(m_height != NULL)
        {
            delete m_height;
            m_height = NULL;
        }
        cout << "析构" << endl;
    }

    int m_age;
    int * m_height;


};

void test01()
{
    Person p1(18, 178);
    cout << p1.m_age << endl;
    cout << *p1.m_height << endl;

    Person p2(p1);
    cout << p2.m_age << endl;
    cout << *p2.m_height << endl;
}

int main()
{
    test01();
    return 0;
}