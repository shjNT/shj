#include "manager.h"


Manager::Manager(){}

Manager::Manager(string name, string pwd)
{
    this->m_name = name;
    this->m_password = pwd;

    // 初始化容器
    this->init_vector();

    // 初始化机房信息文件
    ifstream ifs;
    ifs.open("./example1/file/"+(string)COMPUTER_FILE, ios::in);

    ComputerRoom com;
    while(ifs >> com.m_comid && ifs >> com.m_maxnum)
    {
        v_com.push_back(com);
    }
    ifs.close();
    cout << "机房的数量: " << v_com.size() << endl;
}

void Manager::oper_menu()
{
    cout << "欢迎管理员: " << this->m_name << "登录!" << endl;
    cout << "\t\t -------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          1. 添加账号          |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          2. 查看账号          |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          3. 查看机房          |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          4. 清空预约          |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|          0. 注销登录          |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t -------------------------------\n";
}

// 添加账号
void Manager::add_person()
{
    cout << "请输入添加账号类型" << endl;
    cout << "1. 添加学生" << endl;
    cout << "2. 添加老师" << endl;

    string file_name;
    string tip;
    string error_tip;

    ofstream ofs;
    
    int select = 0;
    cin >> select;

    if (select == 1)
    {
        file_name = STUDENT_FILE;
        tip = "请输入学号: ";
        error_tip = "学号重复，请重新输入: ";
    }
    else
    {
        file_name = TEACHER_FILE;
        tip = "请输入职工号: ";
        error_tip = "职工号重复，请重新输入: ";
    }

    ofs.open("./example1/file/"+file_name, ios::out | ios::app);

    int id;
    string name;
    string pwd;

    cout << tip << endl;
    while (true)
    {
        cin >> id;
        bool ret = check_repeat(id, select);
        if(ret) // 重复
        {
            cout << error_tip<< endl;
        }
        else
        {
            break;
        }
    }

    cout << "请输入姓名: " << endl;
    cin >> name;
    cout << "请输入密码: " << endl;
    cin >> pwd;

    // 向文件中添加数据
    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功!" << endl;

    system("read");
    system("clear");

    ofs.close();

    // 调用初始化
    this->init_vector();
}


void print_student(Student &s)
{
    cout << "学号: " << s.m_id << "\t姓名: " << s.m_name << "\t密码: " << s.m_password<< endl;
}
void print_teacher(Teacher &t)
{
    cout << "职工号: " << t.m_empid << "\t姓名: " << t.m_name << "\t密码: " << t.m_password<< endl;
}

// 查看账号
void Manager::show_person()
{
    cout << "请选择要查看的内容: " << endl;
    cout << "1. 查看所有的学生" << endl;
    cout << "2. 查看所有的老师" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        cout << "所有学生信息如下: " << endl;
        for_each(v_stu.begin(), v_stu.end(), print_student);
    }
    else
    {
        cout << "所有老师信息如下: " << endl;
        for_each(v_tea.begin(), v_tea.end(), print_teacher);
    }

    system("read");
    system("clear");
}

// 查看机房信息
void Manager::show_computer()
{
    cout << "机房的信息如下: " << endl;
    for(vector<ComputerRoom>::iterator it = v_com.begin(); it != v_com.end(); it++)
    {
        cout << "机房编号: " << it -> m_comid << "\t机房容量: " << it->m_maxnum << endl;
    }

    system("read");
    system("clear");
}

// 清空预约
void Manager::clean_file()
{
    ofstream ofs("./example1/file/"+(string)ORDER_FILE, ios::trunc);
    ofs.close();

    cout << "清空成功!" << endl;
    system("read");
    system("clear");
}

// 初始化容器
void Manager::init_vector()
{
    
    v_stu.clear();
    v_tea.clear();


    // 读取信息
    ifstream ifs;
    string file_name = STUDENT_FILE;
    ifs.open("./example1/file/" + file_name, ios::in);
    if(!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }

    Student s;
    while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_password)
    {
        v_stu.push_back(s);
    }
    cout << "学生数量" << v_stu.size() << endl;
    ifs.close();

    file_name = TEACHER_FILE;
    ifs.open("./example1/file/"+file_name, ios::in);
    if(!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }

    Teacher t;
    while (ifs >> t.m_empid && ifs >> t.m_name && ifs >> t.m_password)
    {
        v_tea.push_back(t);
    }
    cout << "老师数量" << v_tea.size() << endl;
    ifs.close();
    
}


// 判断重复
bool Manager::check_repeat(int id, int type)
{
    if (type == 1)
    {
        // 学生
        for(vector<Student>::iterator it = v_stu.begin(); it != v_stu.end(); it++)
        {
            if(id == it->m_id)
            {
                return true;
            }
        }
    }
    else
    {
        // 老师
        for(vector<Teacher>::iterator it = v_tea.begin(); it != v_tea.end(); it++)
        {
            if(id == it->m_empid)
            {
                return true;
            }
        }
    }
    return false;
}