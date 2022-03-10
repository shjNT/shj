#include<iostream>
using namespace std;

// 面向对象
// 封装
// 封装的意义：①将属性和行为作为一个整体； ②将属性和行为加以权限控制


const double PI = 3.1415;

class SloveCircle
{   
    //访问权限
public: //公共权限

    //属性
    int m_r; //半径

    //行为
    double cal_zc()
    {
        return 2 * PI * m_r; //求周长
    }
};


int main(){

    // 创建对象 -->> 实例化
    SloveCircle c1;
    c1.m_r = 10;
    cout << "c1圆的周长:" << c1.cal_zc() << endl;

    return 0;
}