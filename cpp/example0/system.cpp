#include <iostream>
using namespace std;
#include "speech_manager.h"
#include <ctime>

int main()
{
    srand((unsigned int)time(NULL));

    SpeechManager sm;

    // 测试12名选手
    // for(map<int, Speaker>::iterator it = sm.m_speaker.begin(); it != sm.m_speaker.end(); it++)
    // {
    //     cout << "编号: " << it->first << "\t姓名: " << it->second.m_name << "\t分数: " << it->second.m_score[0] << endl;
    // }

    int choice = 0;

    while (true)
    {
        // 显示菜单
        sm.show_menu();

        cout << "请输入您的选择: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1: // 开始比赛
            sm.start_speech();
            break;

        case 2: // 查看往届记录
            sm.show_record();
            break;

        case 3: // 清空比赛记录
            sm.clear_record();
            break;

        case 0: // 退出系统
            sm.exit_system();
            break;

        default:
            system("clear");
            break;
        }
    }
    return 0;
}