#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include <vector>
#include "computer_room.h"
#include <fstream>
#include "global_file.h"
#include "order.h"


class Student : public Identity
{
public:
    // 默认构造
    Student();
    
    // 有参构造
    Student(int id, string name, string pwd);
    
    // 菜单界面
    virtual void oper_menu();
    
    // 申请预约
    void apply_order();

    // 查看预约
    void show_myorder();
    
    // 查看所有预约
    void show_allorder();

    // 取消预约
    void cancel_order();

    int m_id;

    // 机房容器
    vector<ComputerRoom> v_com;
};