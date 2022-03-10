#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <algorithm>

// 评委打分

class Person
{
public:
    Person(string name, int score)
    {
        this->m_name = name;
        this->m_score = score;
    }
    string m_name;
    int m_score;
};

void creat_person(vector<Person> &v)
{
    string name_seed = "ABCDE";
    for(int i=0; i<5; i++)
    {
        string name = "选手";
        name += name_seed[i];
        Person p(name, 0);
        v.push_back(p);
    }
}

void set_score(vector<Person> &v)
{
    for(vector<Person>::iterator it=v.begin(); it != v.end(); it++)
    {
        // 将评分放在deque里面
        deque<int> d;
        for (int i=0; i<10; i++)
        {
            int score = rand()%41 + 60;
            d.push_back(score);
        }
        

        // 去除最高和最低分
        sort(d.begin(), d.end());
        d.pop_front();
        d.pop_back();

        // cout << it->m_name << "打分: " << endl;
        // for(deque<int>::iterator dit = d.begin(); dit !=d.end(); dit++)
        // {
        //     cout << *dit << "  ";
        // }
        // cout << endl;

        // 求平均分
        int sum = 0;
        for(deque<int>::iterator dit = d.begin(); dit !=d.end(); dit++)
        {
            sum += (*dit);
        }
        int avg = sum / d.size();

        it->m_score = avg;
    }
}

void show_score(vector<Person> &v)
{
    for(vector<Person>::iterator it = v.begin(); it !=v.end(); it++)
    {
        cout << "姓名: " << (*it).m_name << "\t平均分: " << (*it).m_score << endl;
    }
}

int main()
{

    // 随机数种子
    srand((unsigned int)time(NULL));


    vector<Person> v;
    creat_person(v);
    // for(vector<Person>::iterator it = v.begin(); it !=v.end(); it++)
    // {
    //     cout << "姓名: " << (*it).m_name << "\t分数: " << (*it).m_score << endl;
    // }

    set_score(v);
    show_score(v);
    return 0;
}