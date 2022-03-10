#include <iostream>
using namespace std;
#include "worker_manager.hpp"
#include "employee.hpp"
#include "manager.hpp"
#include "boss.hpp"

WorkerManager::WorkerManager()
{
    // 文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in); //读文件

    if (!ifs.is_open())
    {
        // cout << "文件不存在" << endl;
        this->m_empnum = 0;
        this->m_emparr = NULL;
        this->m_fileisempty = true;
        ifs.close();
        return;
    }

    // 文件存在但为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) // 文件为空
    {
        // cout << "文件为空" << endl;
        this->m_empnum = 0;
        this->m_emparr = NULL;
        this->m_fileisempty = true;
        ifs.close();
        return;
    }

    // 文件存在不为空
    int num = this->get_empnum();
    this->m_empnum = num;

    this->m_emparr = new Worker *[this->m_empnum]; //开辟空间
    this->init_emp();                              // 将文件中的数据存到数组中
    this->m_fileisempty = false;

    //测试
    // for(int i=0; i<this->m_empnum; i++)
    // {
    //     cout << this->m_emparr[i]->m_id << " " << this->m_emparr[i]->m_name << " " << this->m_emparr[i]->m_depid << endl;
    // }
};

void WorkerManager::show_menu()
{
    cout << "********************************************" << endl;
    cout << "*********** 欢迎使用职工管理系统! **********" << endl;
    cout << "************** 0.退出管理程序 **************" << endl;
    cout << "************** 1.增加职工信息 **************" << endl;
    cout << "************** 2.显示职工信息 **************" << endl;
    cout << "************** 3.删除离职职工 **************" << endl;
    cout << "************** 4.修改职工信息 **************" << endl;
    cout << "************** 5.查找职工信息 **************" << endl;
    cout << "************** 6.按照编号排序 **************" << endl;
    cout << "************** 7.清空所有文档 **************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
};

void WorkerManager::exit_system()
{
    cout << "欢迎下次使用!" << endl;
    // system("read");
    exit(0); //退出程序
};

void WorkerManager::add_emp()
{
    cout << "请输入加入的职工数量: " << endl;
    int add_num = 0;
    cin >> add_num;
    if (add_num > 0)
    {
        // 计算若添加后，所需空间大小
        int new_size = this->m_empnum + add_num;     // 添加后的空间 = 原来的+新赠的
        Worker **new_space = new Worker *[new_size]; // 开辟新空间

        // 原来空间下的数据拷贝到新空间
        if (this->m_emparr != NULL)
        {
            for (int i = 0; i < this->m_empnum; i++)
            {
                new_space[i] = this->m_emparr[i];
            }
        }
        // 批量添加新数据
        for (int i = 0; i < add_num; i++)
        {
            int id;
            string name;
            int depid;
            cout << "请输入" << i + 1 << "个新员工的编号:" << endl;
            cin >> id;
            cout << "请输入" << i + 1 << "个新员工的姓名:" << endl;
            cin >> name;
            cout << "请选择" << i + 1 << "个新员工的岗位:" << endl;
            cout << "1.普通职工"
                 << "\t2.经理"
                 << "\t3.老板" << endl;
            cin >> depid;

            Worker *worker = NULL;
            switch (depid)
            {
            case 1:
                worker = new Employee(id, name, depid);
                break;
            case 2:
                worker = new Manager(id, name, depid);
                break;
            case 3:
                worker = new Boss(id, name, depid);
                break;

            default:
                cout << "请输入正确的岗位" << endl;
                return;
            }

            // 将创建的职工指针保存到数组中
            new_space[this->m_empnum + i] = worker;
        }

        // 释放原有的空间
        delete[] this->m_emparr;

        // 更改新空间的指向
        this->m_emparr = new_space;

        //更新职工人数
        this->m_empnum = new_size;

        // 添加成功后保存到文件中
        this->save();
        cout << "成功添加" << add_num << "名员工" << endl;
        this->m_fileisempty = false;
    }
    else
    {
        cout << "输入有误" << endl;
    }

    system("read");
    system("clear");
}

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    //数据写入
    for (int i = 0; i < this->m_empnum; i++)
    {
        ofs << this->m_emparr[i]->m_id << "  "
            << this->m_emparr[i]->m_name << "  "
            << this->m_emparr[i]->m_depid << endl;
    }

    ofs.close();
}

int WorkerManager::get_empnum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        num++;
    }
    return num;
}

void WorkerManager::init_emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        Worker *worker = NULL;
        if (did == 1)
        {
            worker = new Employee(id, name, did);
        }
        else if (did == 2)
        {
            worker = new Manager(id, name, did);
        }
        else
        {
            worker = new Boss(id, name, did);
        }

        this->m_emparr[index] = worker;
        index++;
    }
    ifs.close();
}

void WorkerManager::show_emp()
{
    // 判断是否为空
    if (this->m_fileisempty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_empnum; i++)
        {
            //利用多态显示
            this->m_emparr[i]->show_info();
        }
    }

    system("read");
    system("clear");
}

int WorkerManager::emp_isexit(int id)
{
    int idx = -1;
    for (int i = 0; i < this->m_empnum; i++)
    {
        if (this->m_emparr[i]->m_id == id)
        {
            idx = i;
            break;
        }
    }
    return idx;
}

void WorkerManager::del_emp()
{
    if (this->m_fileisempty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        cout << "请输入要删除职工的编号:" << endl;
        int id;
        cin >> id;
        int idx = this->emp_isexit(id);

        if (idx != -1)
        {
            for (int i = idx; i < this->m_empnum - 1; i++)
            {
                // 数据迁移
                this->m_emparr[i] = this->m_emparr[i + 1];
            }
            this->m_empnum--;

            this->save(); //同步更新至文件
            cout << "删除成功!" << endl;
        }
        else
        {
            cout << "删除失败，未找到该员工" << endl;
        }
    }

    system("read");
    system("clear");
}

void WorkerManager::mod_emp()
{
    if (this->m_fileisempty)
    {
        cout << "文件不存在或记录为空!" << endl;
    }
    else
    {
        cout << "请输入修改员工的编号:" << endl;
        int id;
        cin >> id;

        int ret = this->emp_isexit(id);
        if (ret != -1)
        {
            // 先删除原来在堆区的数据
            // delete this->m_emparr[ret];
            int new_id;
            string new_name;
            int new_did;

            cout << "查到: " << id << "号职工，请输入新职工号: " << endl;
            cin >> new_id;
            cout << "新姓名: " << endl;
            cin >> new_name;
            cout << "新岗位: " << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> new_did;

            Worker *worker = NULL;
            switch (new_did)
            {
            case 1:
                worker = new Employee(new_id, new_name, new_did);
                break;
            case 2:
                worker = new Manager(new_id, new_name, new_did);
                break;
            case 3:
                worker = new Boss(new_id, new_name, new_did);
                break;
            default:
                break;
            }

            // 更新数组
            this->m_emparr[ret] = worker;
            cout << "修改成功!" << endl;

            // 同步至文件
            this->save();
        }
        else
        {
            cout << "修改失败，查无此人。" << endl;
        }
    }
    system("read");
    system("clear");
}

void WorkerManager::find_emp()
{
    if (this->m_fileisempty)
    {
        cout << "文件为空货不存在!" << endl;
    }
    else
    {
        cout << "请输入查找方式: " << endl;
        cout << "1.按照编号查找" << endl;
        cout << "2.按照姓名查找" << endl;
        int select;
        cin >> select;
        if (select == 1)
        {
            int id;
            cout << "请输入查找的编号: " << endl;
            cin >> id;

            int ret = this->emp_isexit(id);
            if (ret != -1)
            {
                cout << "查找成功，该员工信息如下: " << endl;
                this->m_emparr[ret]->show_info();
            }
            else
            {
                cout << "查无此人!" << endl;
            }
        }
        else if (select == 2)
        {
            string name;
            cout << "请输入查找的姓名: " << endl;
            cin >> name;

            bool flag = false;
            for (int i=0; i<this->m_empnum; i++)
            {
                if(this->m_emparr[i]->m_name == name)
                {
                    flag = true;
                    cout << "查找成功，职工编号为" << this->m_emparr[i]->m_id << "号的员工信息如下: " << endl;
                    this->m_emparr[i]->show_info();
                }
            }
            if (flag == false)
            {
                cout << "查无此人。" << endl;
            }
        }
        else
        {
            cout << "输入有误" << endl;
        }
    }
    system("read");
    system("clear");
}

void WorkerManager::sort_emp()
{
    if (this->m_fileisempty)
    {
        cout << "文件不存在或记录为空!" << endl;
        system("read");
        system("clear");
    }
    else
    {
        cout << "请选择排序方式:" << endl;
        cout << "1.按照职工编号升序排列" << endl;
        cout << "2.按照职工编号降序排列" << endl;
        int select;
        cin >> select;

        // 选择排序
        for (int i=0; i<m_empnum; i++)
        {
            int min_or_max = i;
            for (int j=i+1; j<m_empnum; j++)
            {
                if (select == 1)    // 升序
                {
                    if (this->m_emparr[min_or_max]->m_id > this->m_emparr[j]->m_id)
                    {
                        min_or_max = j;
                    }
                }
                else //降序
                {
                    if (this->m_emparr[min_or_max]->m_id < this -> m_emparr[j]->m_id)
                    {
                        min_or_max = j;
                    }
                }
            }

            // 交换最小或最大值数据
            if (i !=min_or_max)
            {
                Worker *tmp = this->m_emparr[i];
                this->m_emparr[i] = this->m_emparr[min_or_max];
                this->m_emparr[min_or_max] = tmp;
            }
        }
    }
    this->save();
    cout << "排序成功，排序后的结果为: " << endl;
    this->show_emp();
}

void WorkerManager::clean_file()
{
    cout << "确认清空文件？" << endl;
    cout << "1.确认" << endl;
    cout << "2.返回" << endl;
    int select = 0;
    cin >> select;

    if (select == 1)
    {
        // 清空文件
        ofstream ofs(FILENAME, ios::trunc);     //删除文件后重新创建
        ofs.close();
        if (this->m_emparr != NULL)
        {
            // 删除每个对象
            for (int i=0; i < this->m_empnum; i++)
            {
                // delete this->m_emparr[i];
                this->m_emparr[i] = NULL;
            }

            delete[] this->m_emparr;
            this->m_emparr = NULL;
            this->m_empnum = 0;
            this->m_fileisempty = true;
        }

        cout << "清空成功!" << endl;
    }
    system("read");
    system("clear");
}

WorkerManager::~WorkerManager()
{
    if (this->m_emparr != NULL)
    {
        for (int i=0; i<this->m_empnum; i++)
        {
            if(this->m_emparr[i]!= NULL)
            {
                // delete this->m_emparr[i];
                this->m_emparr[i] = NULL;
            }
        }
        delete[] this->m_emparr;
        this->m_emparr = NULL;
    }
};
