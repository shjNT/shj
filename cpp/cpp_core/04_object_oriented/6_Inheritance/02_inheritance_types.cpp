#include<iostream>
using namespace std;

// 继承方式
// ①公共；②保护；③私有

class Base1
{
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;
};


// 公共继承
class Son1:public Base1
{
public:
    void fun()
    {
        m_a = 10;    // 父类中的公共权限成员 在子类中依然是公共权限
        m_b = 20;    // 父类中的保护权限成员 在子类中依然是保护权限
        // m_c = 10;    // 父类中的私有权限成员 在子类中不可访问


    }
};

void test01()
{
    Son1 s1;
    s1.m_a = 100;
    // s1.m_b = 10; // 保护权限不可访问
};

// 保护继承
class Son2: protected Base1
{
    void fun()
    {
        m_a = 10;    // 父类中的公共权限成员 在子类变为保护权限
        m_b = 20;    // 父类中的保护权限成员 在子类中依然是保护权限
        // m_c = 10;    // 父类中的私有权限成员 在子类中不可访问
    }    
};

void test02()
{
    Son2 s1;
    // s1.m_a = 100;  // 保护权限不可访问
    // s1.m_b = 10; // 保护权限不可访问
};


// 私有继承
class Son3: private Base1
{
    void func()
    {
        m_a = 10;    // 父类中的公共权限成员 在子类变为私有权限
        m_b = 20;    // 父类中的保护权限成员 在子类变为私有权限
        // m_c = 10;    // 父类中的私有权限成员 在子类中不可访问

    }
};

class GradSon3: public Son3
{
    void func()
    {
        // m_a = 1; // 父类中的私有权限成员 在子类中不可访问
        // m_b = 3; // 父类中的私有权限成员 在子类中不可访问
    }
};

void test03()
{
    Son3 s1;
    // s1.m_a = 100;  // 私有权限不可访问
    // s1.m_b = 10; // 私有权限不可访问
};

int main()
{

    return 0;
}