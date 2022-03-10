#include<iostream>
using namespace std;

// 虚析构和纯虚析构
// 作用：使用多态时，若子类中有属性开辟到堆区，父类指针在释放时无法调用到子类的析构代码，
                                    // 可将父类中的析构函数改为虚析构或者纯虚析构 

// 语法：
// ①虚析构：virtual ~类名(){}；②纯虚析构：virtual ~类名() = 0;


class Animal
{
public:
    Animal()
    {
        cout << "animal的构造" << endl;
    }

    virtual void speak() = 0;
    
    // // 利用虚析构解决 父类指针释放子类对象时不干净的问题
    // virtual ~Animal()
    // {
    //     cout << "animal的析构" << endl;
    // }

    // 纯虚析构 -> 要有实现
    // 只要有纯虚析构，该类也是抽象类
    virtual ~Animal() = 0;
};

Animal:: ~Animal()
{
    cout << "animal的纯虚析构" << endl;
};

class Cat: public Animal
{
public:

    Cat(string name)
    {
        cout << "cat的构造" << endl;
        m_name = new string(name);
    }
    void speak()
    {
        cout << *m_name << "🐱在叫" << endl;
    }
    
    ~Cat()
    {
        if(m_name != NULL)
        {   
            cout << "cat的析构" << endl;
            delete m_name;
            m_name = NULL;
        }
    }
    string * m_name;

};

class Dog: public Animal
{
public:

    void speak()
    {
        cout << "🐶在叫" << endl;
    }

    // string *name; 
};

void test01()
{
    Animal *animal = new Cat("tom");
    animal->speak();
    delete animal;
};


int main()
{
    test01();
    return 0;
}