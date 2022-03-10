#include <iostream>
using namespace std;
#include "worker_manager.hpp"
#include "worker.hpp"
#include "employee.hpp"
#include "manager.hpp"
#include "boss.hpp"

int main()
{
    // 测试多态
    // Worker *worker = NULL;
    // worker = new Employee(1, "sun", 1);
    // worker->show_info();
    // // delete worker;
    // worker = new Manager(2, "li", 2);
    // worker->show_info();
    // // delete worker;
    // worker = new Boss(3, "niu", 3);
    // worker->show_info();

    // 实例化对象
    WorkerManager wm;

    int choice = 0;
    while (true)
    {
        wm.show_menu(); // 显示菜单
        cout << "请输入您的选择:" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0: // 退出系统
            wm.exit_system();
            break;
        case 1: //增加职工
            wm.add_emp();
            break;
        case 2: //显示职工
            wm.show_emp();
            break;
        case 3: // 删除职工
            wm.del_emp();
            break;
        case 4: //修改职工
            wm.mod_emp();
            break;
        case 5: //查找职工
            wm.find_emp();
            break;
        case 6: // 排序
            wm.sort_emp();
            break;
        case 7: // 清空
            wm.clean_file();
            break;
        default:
            system("clear");
            break;
        }
    }

    return 0;
}