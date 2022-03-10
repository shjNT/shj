#pragma once
#include<iostream>
using namespace std;
#include "worker.hpp"


class Boss: public Worker
{
public:
    Boss(int id, string name, int depid);
    // 显示个人信息
    virtual void show_info();
    // 获取岗位名称
    virtual string get_dep_name();
};