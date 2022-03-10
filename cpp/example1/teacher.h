#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include <string>
#include "order.h"
#include<vector>


class Teacher : public Identity
{
public:
    Teacher();
    Teacher(int emp_id, string name, string pwd);

    virtual void oper_menu();

    // 查看所有预约
    void show_allorder();

    // 审核预约
    void valid_order();

    int m_empid;
};