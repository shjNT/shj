#include<iostream>
using namespace std;
#include "circle.h"


void Cicrle::set_r(int r)
{
    m_r = r;
};

int Cicrle::get_r()
{
    return m_r;
};

void Cicrle::set_center(Point c)
{
    m_c =c;
};

Point Cicrle::get_center()
{
    return m_c;
};
