#include<iostream>
using namespace std;
#include "employee.hpp"

Employee::Employee(int id, string name, int depid)
{
    this->m_id = id;
    this->m_name = name;
    this->m_depid = depid;
}

// 显示个人信息
void Employee::show_info()
{
    cout << "职工编号:" << this->m_id
    << "\t职工姓名:" << this->m_name
    << "\t岗位:" << this->get_dep_name()
    <<"\t岗位职责: 完成经理交代的任务。" << endl;
}

// 获取岗位名称
string Employee::get_dep_name()
{
    return string("员工");
}