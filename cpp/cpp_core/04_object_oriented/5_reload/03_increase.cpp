#include<iostream>
using namespace std;

// 递增运算符重载++ ：通过递增运算符重载，实现自己的整形数据

class MyInteger
{
    friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
    MyInteger()
    {
        m_num = 0;
    }
    // 重载前置++运算符
    MyInteger& operator++()
    {
        m_num++;
        return *this;
    }

    // 重载后置++运算符
    MyInteger operator++(int) // int占位参数，函数重载(区分)
    {
        MyInteger tmp = *this;
        m_num++;
        return tmp;
    }


private:
    int m_num;
};

//重载左移运算符
ostream& operator<<(ostream& cout, MyInteger myint)
{
    cout<< myint.m_num;
    return cout;
}

void test01()
{
    MyInteger myint;
    cout << ++(++myint) << endl;
    cout << myint << endl;
}

void test02()
{
    MyInteger myint;
    // cout << ++(++myint) << endl;
    cout << myint++ << endl;
    cout << myint << endl;
}

int main()
{
    test02();
    return 0;
}