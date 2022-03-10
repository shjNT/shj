#include<iostream>
using namespace std;

// 制作饮品案例

class AbstractDrinking 
{
public:
    // 煮水
    virtual void boil() = 0;

    // 冲泡
    virtual void brew() = 0;

    // 倒入杯中
    virtual void pour() = 0;

    // 加入辅料
    virtual void add() = 0;

    // 制作饮品
    void make_drink()
    {
        boil();
        brew();
        pour();
        add();
    }
};


class Coffee: public AbstractDrinking
{
public:
    // 煮水
    virtual void boil(){
        cout << "煮农夫山泉" << endl;
    };

    // 冲泡
    virtual void brew(){
        cout << "冲coffee" << endl;
    };

    // 倒入杯中
    virtual void pour(){
        cout << "倒入杯中" << endl;
    };

    // 加入辅料
    virtual void add(){
        cout << "加糖和牛奶" << endl;
    };

};


class Tea: public AbstractDrinking
{
public:
    // 煮水
    virtual void boil(){
        cout << "煮矿泉水泉" << endl;
    };

    // 冲泡
    virtual void brew(){
        cout << "泡茶" << endl;
    };

    // 倒入杯中
    virtual void pour(){
        cout << "倒入杯中" << endl;
    };

    // 加入辅料
    virtual void add(){
        cout << "加枸杞" << endl;
    };

};

void do_work(AbstractDrinking * abs)
{
    abs->make_drink();
    delete abs; // 释放 -->> 防止内存泄露
}

void test01()
{
    // 做咖啡
    do_work(new Coffee);
    do_work(new Tea);
}


int main()
{
    test01();
    return 0;
}