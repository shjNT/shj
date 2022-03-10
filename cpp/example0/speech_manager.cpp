#include "speech_manager.h"

SpeechManager::SpeechManager()
{
    // 初始化容器属性
    this->init_speech();

    // 创建12名选手
    this->creat_speaker();

    // 加载往届记录
    this->load_record();
}

void SpeechManager::show_menu()
{
    cout << "****************************************" << endl;
    cout << "*********** 欢迎参加演讲比赛 ***********" << endl;
    cout << "************ 1.开始演讲比赛 ************" << endl;
    cout << "************ 2.查看往届记录 ************" << endl;
    cout << "************ 3.清空比赛记录 ************" << endl;
    cout << "************ 0.退出比赛程序 ************" << endl;
    cout << "****************************************" << endl;
    cout << endl;
}

void SpeechManager::exit_system()
{
    cout << "欢迎下次使用!" << endl;
    exit(0);
}

void SpeechManager::init_speech()
{
    // 容器都置空
    this->v1.clear();
    this->v2.clear();
    this->v_victory.clear();
    this->m_speaker.clear();
    this->m_idx = 1;
    this->m_record.clear();
}

void SpeechManager::creat_speaker()
{
    string name_seed = "ABCDEFGHIJKL";
    for (int i = 0; i < (int)name_seed.size(); i++)
    {
        string name = "选手";
        name += name_seed[i];

        Speaker sp;
        sp.m_name = name;
        for (int j = 0; j < 2; j++)
        {
            sp.m_score[j] = 0;
        }

        // 创建选手编号，并放到v1容器中
        this->v1.push_back(i + 10001);

        // 选手编号及对应选手放入map容器
        this->m_speaker.insert(pair<int, Speaker>(i + 10001, sp));
    }
}

void SpeechManager::start_speech()
{
    // 第一轮
    // 1.抽签
    this->speech_draw();
    // 2.比赛
    this->speech_contest();
    // 3.晋级结果
    this->show_score();
    // 第二轮
    this->m_idx++;
    // 1.抽签
    this->speech_draw();
    // 2.比赛
    this->speech_contest();
    // 3.比赛结果
    this->show_score();

    // 保存至文件
    this->save_record();
    // 重置比赛
    this -> init_speech();   //初始化属性
    this->creat_speaker();   // 创建选手
    this->load_record();    //获取记录


    cout << "本届比赛结束!" << endl;
    system("read");
    system("clear");
}

void SpeechManager::speech_draw()
{
    cout << "第 <<" << this->m_idx << ">> 轮比赛选手正在抽签" << endl;
    cout << "-------------------------" << endl;
    cout << "抽签后的演讲顺序如下: " << endl;

    if (this->m_idx == 1)
    {
        // random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        {
            cout << *it << "  ";
        }
        cout << endl;
    }
    else
    {
        // random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            cout << *it << "  ";
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;

    system("read");
    cout << endl;
}

void SpeechManager::speech_contest()
{
    cout << "----------第 <<" << this->m_idx << ">> 比赛正式开始----------" << endl;

    // 准备临时容器存放小组成绩
    multimap<double, int, greater<double> > group_score;
    int num = 0; // 每6人一组，记录

    vector<int> v_src; //比赛选手容器
    if (this->m_idx == 1)
    {
        v_src = this->v1;
    }
    else
    {
        v_src = this->v2;
    }

    // 遍历所有选手进行比赛
    for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
    {
        num++;
        // 评委打分
        deque<double> d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f; //
            // cout << score << "  ";
            d.push_back(score);
        }
        // cout << endl;

        sort(d.begin(), d.end(), greater<double>()); // 排序
        d.pop_front();                               // 去除最高分
        d.pop_back();                                // 去除最低分

        double sum = accumulate(d.begin(), d.end(), 0.0f); // 总分
        double avg = sum / (double)d.size();               // 平均分
        // cout << "编号: " << *it << "\t姓名: " << this->m_speaker[*it].m_name << "均分: " << avg << endl;

        // 平均分放入map
        this->m_speaker[*it].m_score[this->m_idx - 1] = avg;

        // 将打分数据放入临时小组容器
        group_score.insert(make_pair(avg, *it));

        if (num % 6 == 0)
        {
            cout << "第" << num / 6 << "小组比赛名次: " << endl;
            for (multimap<double, int, greater<double> >::iterator it = group_score.begin(); it != group_score.end(); it++)
            {
                cout << "编号: " << it->second << "\t姓名: " << this->m_speaker[it->second].m_name << "\t得分: "
                     << this->m_speaker[it->second].m_score[this->m_idx - 1] << endl;
            }
            cout << endl;

            // 取走前3名
            int co = 0;
            for (multimap<double, int, greater<double> >::iterator it = group_score.begin(); it != group_score.end() && co < 3; it++, co++)
            {
                if (this->m_idx == 1)
                {
                    v2.push_back((*it).second);
                }
                else
                {
                    v_victory.push_back((*it).second);
                }
            }

            group_score.clear(); //小组容器清空
        }
    }
    cout << "--------------- 第" << this->m_idx << "轮比赛结束 ------------------" << endl;
    system("read");
}

void SpeechManager::show_score()
{
    cout << "------------- 第" << this->m_idx << "轮晋级选手信息如下: -------------" << endl;

    vector<int> v;
    if (this->m_idx == 1)
    {
        v = v2;
    }
    else
    {
        v = v_victory;
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "选手编号: " << (*it) << "\t姓名: " << this->m_speaker[*it].m_name << "\t得分: " << this->m_speaker[*it].m_score[this->m_idx - 1] << endl;
    }
    cout << endl;

    system("read");
    system("clear");

    this->show_menu();
}

void SpeechManager::save_record()
{
    ofstream ofs;
    ofs.open("./example0/speech.csv", ios::out | ios::app); // 输出和追加方式

    for (vector<int>::iterator it = v_victory.begin(); it != v_victory.end(); it++)
    {
        ofs << *it << "," << this->m_speaker[*it].m_score[1] << ",";
    }
    ofs << endl;

    ofs.close();
    cout << "记录保存完毕!!!" << endl;

    //更改状态
    this->file_isempty = false;
}

void SpeechManager::load_record()
{
    ifstream ifs("./example0/speech.csv", ios::in);

    if (!ifs.is_open())
    {
        this->file_isempty = true;
        // cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        this->file_isempty = true;
        // cout << "文件为空" << endl;
        ifs.close();
        return;
    }

    // 文件不为空
    this->file_isempty = false;

    ifs.putback(ch); // 将上面用于判断而读取的字符放回来

    string data;
    int index = 0;

    while (ifs >> data)
    {
        // cout << data << endl;

        vector<string> v; // 存放记录

        // , 的位置
        int pos = -1;
        int start = 0;
        while (true)
        {
            pos = data.find(",", start);
            if (pos == -1)
            {
                break;
            }

            string tmp = data.substr(start, pos - start);
            // cout << tmp << endl;
            v.push_back(tmp);

            start = pos + 1;
        }

        this->m_record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();

    // for(map<int, vector<string> >::iterator it = m_record.begin(); it!=m_record.end(); it++)
    // {
    //     cout << it->first << "bianhao" << it->second[0] << "fen" << it->second[1] << endl;
    // }
}

void SpeechManager::show_record()
{
    if (this->file_isempty)
    {
        cout << "文件不存在或记录为空!" << endl;
    }
    else
    {
        for (int i = 0; i < (int)this->m_record.size(); i++)
        {
            cout << "第" << i + 1 << "届 冠军编号: " << this->m_record[i][0] << " 得分: " << this->m_record[i][1] << "  "
                 << "亚军编号: " << this->m_record[i][2] << " 得分: " << this->m_record[i][3] << "  "
                 << "季军编号: " << this->m_record[i][4] << " 得分: " << this->m_record[i][5] << endl;
        }
    }

    system("read");
    system("clear");
}

void SpeechManager::clear_record()
{
    cout << "是否确定清空文件 ?" << endl;
    cout << "1. 是" << endl;
    cout << "2. 否" << endl;

    int select = 0;
    cin >> select;

    if(select == 1)
    {
        ofstream ofs("/example0/speech.csv", ios::trunc); // trunc清空并重建
        ofs.close();
        // 初始化容器属性
        this->init_speech();

        // 创建12名选手
        this->creat_speaker();

        // 加载往届记录
        this->load_record();

        cout << "文件已清空!" << endl;
    }
    
    system("read");
    system("clear");
}

SpeechManager::~SpeechManager()
{
}