#include <iostream>
using namespace std;
#include "identity.h"
#include <fstream>
#include "global_file.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"


// 进入管理员的子菜单界面
void manager_menu(Identity * &manager) 
{
    while(true)
    {
        // 调用管理员子菜单
        manager->oper_menu();

        // 将父类指针转为子类指针，调用子类里面其他接口
        Manager * man = (Manager*) manager;


        int select = 0;
        cin >> select;

        if(select == 1)     // 添加账号
        {
            // cout << "添加账号" << endl;
            man->add_person();
        }
        else if(select == 2)    // 查看账号
        {
            // cout << "查看账号" << endl;
            man->show_person();
        }
        else if(select == 3)    // 查看机房
        {
            cout << "查看机房" << endl;
            man->show_computer();
        }
        else if(select == 4)    // 清空预约
        {
            cout << "清空预约" << endl;
            man->clean_file();
        }
        else
        {
            // delete man;     // 删除堆区对象
            cout << "注销成功!" << endl;
            system("read");
            system("clear");
            return;
        }
    }
}


// 进入学生的子菜单界面
void student_manue(Identity * &student)
{
    while (true)
    {
        //调用学生子菜单
        student->oper_menu();

        Student * stu = (Student *) student;    //强转父类指针为子类指针，去调用子类中特有的成员

         int select = 0;
         cin >> select;

         if(select == 1)
         {
             // 申请预约
             stu->apply_order();
         }
         else if(select == 2)
         {
            //  查看自身预约
            stu->show_myorder();
         }
         else if(select == 3)
         {
            //  查看所有预约
            stu->show_allorder();
         }
         else if(select == 4)
         {
            //  取消预约
            stu->cancel_order();
         }
         else
         {
            //  注销登录
            // delete student;
            cout << "注销成功" << endl;

            system("read");
            system("clear");
            return;
         }
    }
    
}


// 进入教师子菜单界面
void teacher_manue(Identity * &teacher)
{
    while(true)
    {
        // 调用子菜单界面
        teacher->oper_menu();

        Teacher * tea = (Teacher *)teacher;

        int select = 0;
        cin >> select;

        if(select == 1)
        {
            // 查看所有预约
            tea->show_allorder();
        }
        else if(select == 2)
        {
            // 审核预约
            tea->valid_order();
        }
        else
        {
            // 注销登录
            cout << "注销成功" << endl;
            system("read");
            system("clear");
            return;
        }
    }
}


// 登录功能
void log_in(string file_name, int type)
{
    Identity * person = NULL;   // 父类指针，用于指向子类对象

    //读文件
    ifstream ifs;
    ifs.open("./example1/file/"+file_name, ios::in);

    // 判断文件是否打开成功
    if(!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    // 准备接收用户输入信息
    int id = 0;
    string name;
    string pwd;

    // 判断身份
    if (type == 1)
    {
        cout << "请输入你的学号: " << endl;
        cin >> id;
    }
    else if(type == 2)
    {
        cout << "请输入您的职工号: " << endl;
        cin >> id;
    }

    cout << "请输入用户名: " << endl;
    cin >> name;

    cout << "请输入密码: " << endl;
    cin >> pwd;

    if(type == 1)
    {
        // 学生验证
        int fid;    // 从文件中获取的id
        string fname;   // 从文件中获取的姓名
        string fpwd;    // 从文件中获取的密码

        while(ifs >> fid && ifs >> fname && ifs>> fpwd)
        {
            // 与用户输入信息对比
            if(fid == id && fname == name && fpwd == pwd)
            {
                cout << "学生验证登录成功!" << endl;
                system("read");
                system("clear");

                person = new Student(id, name, pwd);

                // 进入学生的子菜单
                student_manue(person);

                return;
            }
        }

    }
    else if(type == 2)
    {
        // 教师验证
        int fid;    // 从文件中获取的id
        string fname;   // 从文件中获取的姓名
        string fpwd;    // 从文件中获取的密码

        while(ifs >> fid && ifs >> fname && ifs>> fpwd)
        {
            // 与用户输入信息对比
            if(fid == id && fname == name && fpwd == pwd)
            {
                cout << "教师验证登录成功!" << endl;
                system("read");
                system("clear");

                person = new Teacher(id, name, pwd);

                // 进入教师的子菜单
                teacher_manue(person);

                return;
            }
        }
    }
    else if(type == 3)
    {
        // 管理员验证
        string fname;   // 从文件中获取的姓名
        string fpwd;    // 从文件中获取的密码

        while(ifs >> fname && ifs>> fpwd)
        {
            // 与用户输入信息对比
            if(fname == name && fpwd == pwd)
            {
                cout << "管理员验证登录成功!" << endl;
                system("read");
                system("clear");

                person = new Manager(name, pwd);

                // 进入管理员的子菜单
                manager_menu(person);

                return;
            }
        }

    }

    cout << "验证登录失败!" << endl;
    system("read");
    system("clear");
}



int main()
{
    int select = 0;
    while(true)
    {
        cout<< endl;
        cout << "==================== 欢迎来到机房预约系统 ====================" << endl;
        cout << "请输入您的身份 " << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1. 学生代表          |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|            2. 老师            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|           3. 管理员           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|            0. 退出            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: " << endl;

        cin >> select;

        switch (select)
        {
        case 1:     // 学生
            log_in(STUDENT_FILE, 1);
            break;

        case 2:     // 老师
            log_in(TEACHER_FILE, 2);
            break;

        case 3:     // 管理员
            log_in(ADMIN_FILE, 3);
            break;

        case 0:     // 退出
            cout << "欢迎下次使用!" << endl;
            system("read");
            return 0;
            break;
        
        default:
            cout << "输入有误，请重新选择!" << endl;
            system("read");
            system("clear");
            break;
        }
    }
    
    // system("read");
    return 0;
}