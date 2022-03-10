#include <iostream>
using namespace std;
#include "boss.hpp"

Boss::Boss(int id, string name, int depid)
{
    this->m_id = id;
    this->m_name = name;
    this->m_depid = depid;
}

void Boss::show_info()
{
    cout << "职工编号:" << this->m_id
    << "\t职工姓名:" << this->m_name
    << "\t岗位:" << this->get_dep_name()
    <<"\t岗位职责: 统筹全局!" << endl;
}

string Boss::get_dep_name()
{
    return string("老板");
}