#include<iostream>
using namespace std;

// 继承中构造和析构的顺序

// 子类继承父类后，当创建子类对象，也会调用父类的构造函数


class Base
{
public:
    Base()
    {
        cout << "Base的构造" << endl;
    }

    ~Base()
    {
        cout << "Base的析构" << endl;
    }
};

class Son: public Base
{
public:
    Son()
    {
        cout << "Son的构造" << endl;
    }

    ~Son()
    {
        cout << "Son的析构" << endl;
    }
};

void test01()
{
    // Base b;
    Son s;
    // 继承中构造和析构顺序：先构造父类，再构造子类，析构的顺序与构造的顺序相反
}

int main()
{
    test01();
    return 0;
}