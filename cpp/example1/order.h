#pragma once
#include <iostream>
using namespace std;
#include "global_file.h"
#include <fstream>
#include <map>

class OrderFile
{
public:
    OrderFile();

    // 更新预约记录
    void update_order();

    // 记录预约条数
    int m_size;

    // 记录所有预约信息的容器
    map<int, map<string, string> > m_order_data;
};
