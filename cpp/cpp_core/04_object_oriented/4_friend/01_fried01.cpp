#include<iostream>
using namespace std;

// 友元
// 作用：让一个函数或者类访问另一个类中的私有成员

// 3种实现
// ①全局函数做友元； ②类做友元； ③成员函数做友元


class Building
{
    // friend 修饰全局函数声明，作为友元，可以访问类中私有属性
    friend void good_gay(Building * b);

public:
    Building()
    {
        m_sitting_room = "客厅";
        m_bedromm = "卧室";
    }

public:
    string m_sitting_room;

private:
    string m_bedromm;

};

// 全局函数
void good_gay(Building * b)
{
    cout<< "全局函数访问: " << b->m_sitting_room << endl;
    cout<< "全局函数访问: " << b->m_bedromm << endl;
}

void test01()
{   
    Building b1;
    good_gay(&b1);
}

int main()
{
    test01();

    return 0;
}