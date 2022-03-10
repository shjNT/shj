#include <iostream>
using namespace std;
#include "manager.hpp"

Manager::Manager(int id, string name, int depid)
{
    this->m_id = id;
    this->m_name = name;
    this->m_depid = depid;
}

void Manager::show_info()
{
    cout << "职工编号:" << this->m_id
    << "\t职工姓名:" << this->m_name
    << "\t岗位:" << this->get_dep_name()
    <<"\t岗位职责: 完成老板交代的任务，传达给普通员工。" << endl;;
}

string Manager::get_dep_name()
{
    return string("经理");
}