#pragma once
#include <iostream>
using namespace std;
#include "point.h"

class Cicrle
{
public:
    void set_r(int r);
    int get_r();
    void set_center(Point c);
    Point get_center();

private:
    Point m_c;
    int m_r;
};