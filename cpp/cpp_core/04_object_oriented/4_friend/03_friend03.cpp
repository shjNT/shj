#include<iostream>
using namespace std;

// ③成员函数做友元


class Building;
class GoodGay
{
public:
    GoodGay();
    void visit(); // visit函数访问Building中的私有成员
    void visit02(); // 不可以访问Building中的私有成员
    Building * building;
};

class Building
{
    // 成员函数做友元
    friend void GoodGay::visit();
public:
    Building();
public:
    string m_sitting_room;

private:
    string m_bedroom;
};

// 类外实现成员函数
Building::Building()
{
    m_sitting_room = "客厅";
    m_bedroom = "卧室";
}

GoodGay::GoodGay()
{
    building = new Building;
}

void GoodGay::visit()
{
    cout << "visit正在访问: " << building->m_sitting_room << endl;
    cout << "visit正在访问: " << building->m_bedroom << endl;
}
void GoodGay::visit02()
{
    cout << "visit2正在访问: " << building->m_sitting_room << endl;
    // cout << "visit正在访问: " << building->m_bedroom << endl;
}

void test01()
{
    GoodGay gg;
    gg.visit();
    gg.visit02();
}

int main()
{
    test01();

    return 0;
}