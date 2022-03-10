#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <ctime>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

// 创建员工
class Worker
{
public:
    string m_name;
    int m_salary;
};

void create_worker(vector<Worker> &v)
{
    string name_seed = "ANCDEFGHIJ";
    for(int i=0; i< 10; i++)
    {
        Worker w;
        w.m_name = "员工";
        w.m_name += name_seed[i];

        w.m_salary = rand()%10000 + 10000; // 10000~19999

        // 将创建的员工放入vector
        v.push_back(w);
    }
}


//员工分组
void set_group(vector<Worker> &v, multimap<int, Worker> &m)
{
    for(vector<Worker>::iterator it = v.begin(); it!=v.end(); it++)
    {
        // 产生随机部门编号
        int id = rand() % 3;

        // 插入multimap
        m.insert(make_pair(id, *(it)));
    }
}

// 分组显示
void show_worker_by_group(multimap<int, Worker> &m)
{
    cout << "策划部门: " << endl;
    multimap<int, Worker> ::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA);
    int index = 0;
    for( ; pos!=m.end() && index<count; pos++, index++)
    {
        cout << "姓名: " << pos->second.m_name << "  工资: " << pos->second.m_salary << endl;
    }

    cout << "美术部门: " << endl;
    multimap<int, Worker> ::iterator pos1 = m.find(MEISHU);
    int count1 = m.count(MEISHU);
    int idx = 0;
    for( ; pos1!=m.end() && idx<count1; pos1++, idx++)
    {
        cout << "姓名: " << pos1->second.m_name << "  工资: " << pos1->second.m_salary << endl;
    }

    cout << "研发部门: " << endl;
    multimap<int, Worker> ::iterator pos2 = m.find(MEISHU);
    int count2 = m.count(MEISHU);
    int idx2 = 0;
    for( ; pos2!=m.end() && idx2<count2; pos2++, idx2++)
    {
        cout << "姓名: " << pos2->second.m_name << "  工资: " << pos2->second.m_salary << endl;
    }
}

int main()
{
    srand((unsigned int) time(NULL));
    // 1.创建员工
    vector<Worker> v;
    create_worker(v);

    // 2.员工分组
    multimap<int, Worker> m;
    set_group(v, m);

    // 3.分组显示
    show_worker_by_group(m);
    // for(vector<Worker>::iterator it = v.begin(); it!=v.end(); it++)
    // {
    //     cout << "姓名:" << it->m_name << "\t工资:" << it->m_salary << endl; 
    // }
    return 0;
}