#include<iostream>
using namespace std;

// 菱形继承

// 利用虚继承可以解决菱形继承的问题

class Animal
{
public:
    int m_age;
};
class Sheep: virtual public Animal{};   // 继承之前加关键字 virtual 变为虚继承; Animal称为虚基类
class Tuo: virtual public Animal{};
class SheepTuo: public Sheep, public Tuo{};

void test01()
{
    SheepTuo st;
    st.Sheep::m_age = 18;
    st.Tuo::m_age = 38;

    cout << st.Sheep::m_age << endl;
    cout << st.Tuo::m_age << endl;
    cout << st.m_age << endl;
}

int main()
{
    test01();
    return 0;
}