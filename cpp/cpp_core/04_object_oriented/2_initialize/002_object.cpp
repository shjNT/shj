#include<iostream>
using namespace std;

// 构造函数的分类及调用

// ①按参数分：有参构造(默认)和无参构造；②按类型分：普通构造和拷贝构造
// 三种调用方式：括号法、显示法、隐式转换法

class Person
{
public:
    Person()
    {
        cout << "Person的无参构造函数调用" << endl;
    }

    Person(int a)
    {
        age = a;
        cout << "Person的有参构造函数调用" << endl;
    }
    // 拷贝构造函数
    Person(const Person &p)
    {
        age = p.age;    //将传入的人身上的所有属性，拷贝到当前身上
        cout << "Person的拷贝构造函数调用" << endl;
    }

    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }

    int age;
};


// 调用
void test01()
{
    //1.括号
    // Person p1; //默认构造函数
    // Person p2(10); //有参构造
    // Person p3(p2); // 拷贝构造

    // cout << "p2的年龄:" << p2.age << endl;
    // cout << "p3的年龄:" << p3.age << endl;

    //注意：调用默认构造函数时不要加()
    // Person p1(); // -> 编译器会认定为这是函数声明，不会认为创建对象

    // 2.显示法
    // Person p1; // 无参
    // Person p2 = Person(10); //有参
    // Person p3 = Person(p2); //拷贝

    // Person(10); //匿名对象 -> 当前行执行结束后，系统会立即回收匿名对象
    // cout << "ssssss" << endl;

    // 注意：不要利用拷贝构造函数初始化匿名对象
    // Person(p2);

    // 3.隐式转换法
    Person p4 = 10; // 相当于Person p4 =Person(10)
    Person p5 = p4; // 拷贝构造；

}


int main()
{
    // Person p;
    test01();
    return 0;
}