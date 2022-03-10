#include "teacher.h"

Teacher::Teacher()
{}

Teacher::Teacher(int emp_id, string name, string pwd)
{
    this->m_empid = emp_id;
    this->m_name = name;
    this ->m_password = pwd;
}

void Teacher::oper_menu()
{
    cout << "欢迎教师: " << this->m_name << "登录!" << endl;
    cout << "\t\t--------------------------------------\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|            1. 查看所有预约         |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|            2. 审核预约             |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|            0. 注销登录             |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t--------------------------------------\n";
    
    cout << "请输入您的选择: " << endl;
}

// 查看所有预约
void Teacher::show_allorder()
{
    OrderFile ord;
    ord.update_order();
    if (ord.m_size == 0)
    {
        cout << "无预约记录!" << endl;
        system("read");
        system("clear");
        return;
    }

    for(int i=0; i<ord.m_size; i++)
    {
        cout << "第" << i+1 << "条预约 -> ";
        cout << "预约日期: 周"  << ord.m_order_data[i]["date"];
        cout << "  时间段: " << (ord.m_order_data[i]["iterval"] == "1" ? "上午" : "下午");
        cout << "  学号: " << ord.m_order_data[i]["stu_id"];
        cout << "  姓名: " << ord.m_order_data[i]["stu_name"];
        cout << "  机房号: " << ord.m_order_data[i]["room_id"] << "  ";
        string status = "状态: ";
        // 1.审核中  2.已预约  -1.预约失败  0取消预约
        if(ord.m_order_data[i]["status"] == "1")
        {
            status += "审核中";
        }
        else if (ord.m_order_data[i]["status"] == "2")
        {
            status += "预约成功";
        }
        else if (ord.m_order_data[i]["status"] == "-1")
        {
            status += "预约失败，审核未通过";
        }
        else
        {
            status += "预约已取消";
        }
        cout << status << endl;
    }
    system("read");
    system("clear");
}

// 审核预约
void Teacher::valid_order()
{
    OrderFile ord;
    ord.update_order();
    if (ord.m_size == 0)
    {
        cout << "无预约记录!" << endl;
        system("read");
        system("clear");
        return;
    }

    vector<int> v;
    int index = 0;

    cout << "待审核的记录如下: " << endl;
    for(int i=0; i<ord.m_size; i++)
    {
        if(ord.m_order_data[i]["status"] == "1")
        {
            v.push_back(i);
            cout << "第" << ++index << "条待审核的预约 -> ";
            cout << "预约日期: 周"  << ord.m_order_data[i]["date"];
            cout << "  时间段: " << (ord.m_order_data[i]["iterval"] == "1" ? "上午" : "下午");
            cout << "  学号: " << ord.m_order_data[i]["stu_id"];
            cout << "  姓名: " << ord.m_order_data[i]["stu_name"];
            cout << "  机房号: " << ord.m_order_data[i]["room_id"] << "  ";
            string status = "状态: 审核中";
            cout << status << endl;
        }
        
    }

    cout << "请输入审核的预约记录, 0代表返回" << endl;
    int select = 0;
    int ret = 0;

    while(true)
    {
        cin >> select;
        if(select >= 0 && select <= (int)v.size())
        {
            if(select == 0)
            {
                break;
            }
            else
            {
                cout << "请输入审核结果:" << endl;
                cout << "1. 通过" << endl;
                cout << "2. 不通过" << endl;

                cin >> ret;
                if(ret == 1)
                {
                    ord.m_order_data[v[select-1]]["status"] = "2";
                }
                else
                {
                    ord.m_order_data[v[select-1]]["status"] = "-1";
                }
                ord.update_order();
                cout << "审核完毕!" << endl;
                break;
            }
            
        }
        
        cout << "输入有误， 请重新输入!" << endl;
    }
    system("read");
    system("clear");
}