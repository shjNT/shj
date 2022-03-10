#include<iostream>
using namespace std;

// 多态

// 多态的分类：
// ①静态多态：函数重载和运算符重载属于静态多态，复用函数名
// ②动态多态：派生类和虚函数实现运行时多态

// 区别：
// ①静态多态的函数地址早绑定：编译阶段确定函数地址
// ②动态多态的函数地址晚绑定：运行阶段确定函数地址


// 动态多态的满足条件：①有继承关系；②子类重写父类的虚函数
// 动态多态的使用：父类的指针或引用指向子类对象
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

int main()
{
    test01();
    return 0;
}