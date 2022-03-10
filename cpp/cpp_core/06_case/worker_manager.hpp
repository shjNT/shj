#pragma once    // 防止头文件重复包含
#include <iostream>     // 包含输入，输出流头文件
using namespace std;    // 使用标准命名空间
#include "worker.hpp"
#include <fstream>

#define FILENAME "emp_file.txt"

class WorkerManager
{
public:
    WorkerManager();    // 构造

    // 展示菜单
    void show_menu();

    // 退出系统
    void exit_system();

    // 记录职工人数
    int m_empnum;
    // 职工数组指针
    Worker ** m_emparr;

    // 添加员工
    void add_emp();

    // 保存文件
    void save();

    // 标志文件是否为空
    bool m_fileisempty;

    // 统计文件中人数
    int get_empnum();

    // 初始化员工
    void init_emp();

    // 显示员工
    void show_emp();

    // 职工是否存在
    int emp_isexit(int id);
    
    // 删除员工
    void del_emp();

    // 修改员工
    void mod_emp();

    // 查找职工
    void find_emp();

    // 排序
    void sort_emp();

    // 清空文件
    void clean_file();

    ~WorkerManager();   // 析构
};

