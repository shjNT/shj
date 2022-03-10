#include "student.h"

// 默认构造
Student::Student()
{}

// 有参构造
Student::Student(int id, string name, string pwd)
{
    this->m_id = id;
    this->m_name = name;
    this->m_password = pwd;

    // 初始化机房信息
    ifstream ifs;
    ifs.open("./example1/file/"+(string)COMPUTER_FILE, ios::in);

    ComputerRoom com;
    while(ifs >> com.m_comid && ifs >> com.m_maxnum)
    {
        v_com.push_back(com);
    }
    ifs.close();
}

// 菜单界面
void Student::oper_menu()
{
    cout << "欢迎学生代表: " << this->m_name << "登录!" << endl;
    cout << "\t\t--------------------------------------\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|            1. 申请预约             |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|            2. 查看我的预约         |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|            3. 查看所有预约         |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|            4. 取消预约             |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t|            0. 注销登录             |\n";
    cout << "\t\t|                                    |\n";
    cout << "\t\t--------------------------------------\n";
}

// 申请预约
void Student::apply_order()
{
    cout << "机房开房时间为周一至周五!" << endl;
    cout << "请输入申请预约的时间: " << endl;
    cout << "1. 周一" << endl;
    cout << "2. 周二" << endl;
    cout << "3. 周三" << endl;
    cout << "4. 周四" << endl;
    cout << "5. 周五" << endl;

    int date = 0;   //日期
    int interval = 0;   // 时间段
    int room = 0;    // 机房

    while(true)
    {
        cin >> date;
        if(date >=1 && date <=5)
        {
            break;
        }
        else
        {
            cout << "输入有误, 请重新输入: " << endl;
        }
    }

    cout << "请输入申请预约的时间段: " << endl;
    cout << "1. 上午" << endl;    
    cout << "2. 下午" << endl;   
    while(true)
    {
        cin >> interval;
        if(interval >=1 && interval <= 2){break;}else{cout << "输入有误, 请重新输入: " << endl;}
    }

    cout << "请选择机房: " << endl;
    for(int i=0 ; i<(int)v_com.size(); i++)
    {
        cout << v_com[i].m_comid << "号机房的容量为: " << v_com[i].m_maxnum << endl;
    }
    while(true)
    {
        cin >> room;
        if(room >= 1 && room <=3){break;}else{cout << "输入有误, 请重新输入: " << endl;}
    }
    
    cout << "预约成功!审核中···" << endl;

    ofstream ofs;
    ofs.open("./example1/file/"+(string)ORDER_FILE, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stu_id:" << this->m_id << " ";
    ofs << "stu_name:" << this->m_name << " ";
    ofs << "room_id:" << room << " ";
    ofs << "status:" << 1 << endl;
    ofs.close();

    system("read");
    system("clear");
}

// 查看预约
void Student::show_myorder()
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

    for(int i =0; i < ord.m_size; i++)
    {
        if(this->m_id == atoi(ord.m_order_data[i]["stu_id"].c_str()) )
         // 将string转为int， .c_str()转为c语言字符串(const char *), atoi()转为整形
        {
            // 找到自身预约
            cout << "预约日期: 周" << ord.m_order_data[i]["date"];
            cout << "\t时间段: " << (ord.m_order_data[i]["interval"] == "1" ? "上午" : "下午");
            cout << "\t机房号: " << ord.m_order_data[i]["room_id"] << "\t";
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
    }
    system("read");
    system("clear");
    
}

// 查看所有预约
void Student::show_allorder()
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

// 取消预约
void Student::cancel_order()
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

    cout << "审核中或者预约成功的记录可以取消, 请输入取消的记录" << endl;

    vector<int> v;  //记录存放在大容器中的编号
    int index = 1;
    for(int i=0; i<ord.m_size; i++)
    {
        // 判断自己的预约
        if(this->m_id == atoi(ord.m_order_data[i]["stu_id"].c_str()))
        {
            // 筛选状态， 审核中或者预约成功可取消
            if(ord.m_order_data[i]["status"] == "1" || ord.m_order_data[i]["status"] == "2")
            {
                v.push_back(i);
                cout << "第" << index++ << "条预约 -> ";
                cout << "预约日期: 周"  << ord.m_order_data[i]["date"];
                cout << "  时间段: " << (ord.m_order_data[i]["iterval"] == "1" ? "上午" : "下午");
                cout << "  机房号: " << ord.m_order_data[i]["room_id"] << "  ";
                string status = "状态: ";
                if(ord.m_order_data[i]["status"] == "1")
                {
                    status += "审核中";
                }
                else if (ord.m_order_data[i]["status"] == "2")
                {
                    status += "预约成功";
                }
                
                cout << status << endl;
            }
        }
    }

    cout << "请输入取消的申请记录, 0代表返回" << endl;
    int select =0;
    while(true)
    {
        cin >> select;
        if(select >=0 && select <= (int)v.size())
        {
            if(select == 0)
            {
                break;
            }
            else
            {
                ord.m_order_data[v[select-1]]["status"] = "0";
                ord.update_order();

                cout << "取消成功" << endl;
                break;
            }

        }

        cout << "输入有误, 请重新输入" << endl;
    }

    system("read");
    system("clear");
}