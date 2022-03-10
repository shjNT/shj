#include<iostream>
using namespace std;

// ②类做友元
class Building
{
    // 友元为类，访问私有属性
    friend class GoodGay;
public:
    Building();

public:
    string m_sitting_room;

private:
    string m_bedroom;
};


class GoodGay
{
public:
    GoodGay();
public:
    void visit(); //访问building中的属性
    Building * building;

};

// 类外写成员函数
Building::Building()
{
    m_sitting_room = "客厅";
    m_bedroom = "卧室";
};

GoodGay::GoodGay()
{
    building = new Building;
};

void GoodGay::visit()
{
    cout << "GoodGay类正在访问:" << building->m_sitting_room << endl;
    cout << "GoodGay类正在访问:" << building->m_bedroom << endl;
};


void test01()
{
    GoodGay gg;
    gg.visit();
}

int main()
{
    test01();
    return 0;
}
