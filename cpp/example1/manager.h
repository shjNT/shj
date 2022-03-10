#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include <fstream>
#include "global_file.h"
#include "student.h"
#include "teacher.h"
#include "computer_room.h"
#include <vector>


class Manager : public Identity
{
public:
    Manager();
    Manager(string name, string pwd);

    virtual void oper_menu();

    // 添加账号
    void add_person();

    // 查看账号
    void show_person();

    // 查看机房信息
    void show_computer();

    // 清空预约
    void clean_file();

    // 初始化容器
    void init_vector();

    // 判断重复
    bool check_repeat(int id, int type);

    // 学生容器
    vector<Student> v_stu;

    // 教师容器
    vector<Teacher> v_tea;

    // 机房容器
    vector<ComputerRoom> v_com;
};