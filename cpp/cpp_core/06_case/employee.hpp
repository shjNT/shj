// 普通员工
#pragma once
#include<iostream>
using namespace std;
#include "worker.hpp"

class Employee: public Worker
{
public:
    Employee(int id, string name, int depid);
    // 显示个人信息
    void show_info();
    // 获取岗位名称
    string get_dep_name();
};