// 创建管理类
/*
1.菜单界面和用户的交互
2.流程控制
3.文件交互
*/

#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <deque>
#include <numeric>
#include "speaker.h"
#include <fstream>



// 设计演讲管理类

class SpeechManager
{
public:
    SpeechManager();

    // 展示菜单
    void show_menu();

    // 初始化属性
    void init_speech();

    // 创建12名选手
    void creat_speaker();

    // 比赛流程控制
    void start_speech();

    // 抽签
    void speech_draw();

    // 比赛
    void speech_contest();

    // 显示得分
    void show_score();

    //保存文件
    void save_record();

    // 读取文件
    void load_record();

    // 显示往届记录
    void show_record();

    // 清空文件
    void clear_record();

    // 判断文件是否为空
    bool file_isempty;
    // 存放往届记录的容器
    map<int, vector<string> > m_record;

    // 退出系统
    void exit_system();

    ~SpeechManager();


    // 成员属性
    vector<int> v1;     // 第一轮选手编号容器
    vector<int> v2;     // 第一轮晋级选手编号容器
    vector<int> v_victory;  // 胜出前三名

    map<int, Speaker> m_speaker;    // 选手和对应编号

    int m_idx;   //比赛轮数
};