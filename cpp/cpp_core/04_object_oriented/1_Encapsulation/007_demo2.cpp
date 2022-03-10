#include<iostream>
using namespace std;
#include "point.h"
#include "circle.h"

// 判断点和圆的位置关系
void judge(Cicrle &c, Point &p)
{
    int distance = (c.get_center().get_x() - p.get_x()) * (c.get_center().get_x() - p.get_x()) +
                    (c.get_center().get_y() - p.get_y()) * (c.get_center().get_y() - p.get_y());
    int r_distance = c.get_r() * c.get_r();

    if(distance == r_distance)
    {
        cout << "点在圆上" << endl;
    }
    else if(distance > r_distance)
    {
        cout << "点在圆外" << endl;
    }
    else
    {
        cout << "点在圆内" << endl;
    }
};

int main()
{

    return 0;
}