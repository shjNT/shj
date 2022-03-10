#include<iostream>
using namespace std;

// 类模板与继承
// 注意点:
// ①当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
// ②若不指定，编译器无法给子类分配内存
// ③若想灵活的指定出父类中T的类型，子类也需要变为类模板

template<class T>
class Base
{
public:
    T m;
};


class Son: public Base<string>
{

};
void test01()
{
    Son s;
    cout << sizeof(s.m) << endl;
}

// 若想灵活的指定出父类中T的类型，子类也需要变为类模板
template<class T1, class T2>
class Son2: public Base<T2>
{
public:
    Son2()
    {
        cout << "T1的类型:" << typeid(T1).name() << endl;
    }
    
    T1 obj;
};
void test02()
{
    Son2<int, char> s;
}


int main()
{
    test01();
    test02();
    return 0;
}