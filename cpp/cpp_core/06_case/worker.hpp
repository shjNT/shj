#pragma once
#include <iostream>
using namespace std;

class Worker
{
public:
    // 显示个人信息
    virtual void show_info() = 0;
    // 获取岗位名称
    virtual string get_dep_name() = 0;

    int m_id;
    string m_name;
    int m_depid;

    // virtual ~Worker()=0;
};