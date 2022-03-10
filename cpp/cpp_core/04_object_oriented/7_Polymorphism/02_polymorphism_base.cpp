#include<iostream>
using namespace std;

// 动态多态
// 多态满足条件： ①有继承关系；②子类重写父类虚函数；
// 多态使用条件： 父类指针或引用指向子类对象

class Animal
{
public:
    // 虚函数
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

class Cat: public Animal
{
public:
    void speak()
    {
        cout << "猫在说话" << endl;
    }
};

class Dog: public Animal
{
public:
    void speak()
    {
        cout << "🐶在说话" << endl;
    }
};


// 执行说话的函数
// 地址早绑定 ->> 地址晚绑定  通过虚函数
void do_speak(Animal &animal)
{
    animal.speak();
}

void test01()
{
    Cat cat;
    do_speak(cat);
    Dog dog;
    do_speak(dog);
}

void test02()
{
    cout << sizeof(Animal) << endl;
    cout << sizeof(Cat) << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}

