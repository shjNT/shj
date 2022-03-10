#pragma once
#include <iostream>
using namespace std;

class Identity
{
public:
    // 子类的菜单 -->> 利用多态：纯虚函数
    // (纯虚函数的作用: 子类若不重写，无法实例化对象)
    virtual void oper_menu() = 0;

    string m_name;
    string m_password;
};