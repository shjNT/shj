#include<iostream>
using namespace std;

// 继承中的对象模型

class Base
{
public:
    int m_a;
protected:
    int m_b;
private:
    int m_c;

};

class Son: public Base
{
public:
    int m_d;
};

void test01()
{
    // 父类中所有非静态成员属性都会被子类继承;
    // 父类中私有成员属性是被编译器隐藏了，因此是访问不到的，但确实是被继承了
    cout << sizeof(Son) << endl;
}


int main()
{
    test01();
    return 0;
}