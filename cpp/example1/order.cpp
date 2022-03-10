
#include "order.h"


OrderFile::OrderFile()
{
    ifstream ifs;
    ifs.open("./example1/file/"+(string)ORDER_FILE, ios::in);

    string date;
    string interval;
    string stu_id;
    string stu_name;
    string room_id;
    string status;

    this->m_size = 0;   //预约数量

    while(ifs >> date && ifs >> interval && ifs >> stu_id && ifs >> stu_name && ifs >> room_id && ifs >> status)
    {
        // cout << date << endl;
        // cout << interval << endl;
        // cout << stu_id << endl;
        // cout << stu_name << endl;
        // cout << room_id << endl;
        // cout << status << endl;
        // cout << endl;

        // data
        string key;
        string value;
        map<string, string> m;

        int pos = date.find(":");
        if(pos != -1)
        {
            key = date.substr(0, pos);
            value = date.substr(pos+1, date.size() - pos);
            m.insert(make_pair(key, value));
        }
        
        // cout << "key= " << key << endl;
        // cout << value << endl;

        // 截取时间段
        pos = interval.find(":");
        if(pos != -1)
        {
            key = interval.substr(0, pos);
            value = interval.substr(pos+1, interval.size() - pos);
            m.insert(make_pair(key, value));
        }
        // 截取学号
        pos = stu_id.find(":");
        if(pos != -1)
        {
            key = stu_id.substr(0, pos);
            value = stu_id.substr(pos+1, stu_id.size() - pos);
            m.insert(make_pair(key, value));
        }

        // 截取姓名
        pos = stu_name.find(":");
        if(pos != -1)
        {
            key = stu_name.substr(0, pos);
            value = stu_name.substr(pos+1, stu_name.size() - pos);
            m.insert(make_pair(key, value));
        }
        
        // 截取机房号
        pos = room_id.find(":");
        if(pos != -1)
        {
            key = room_id.substr(0, pos);
            value = room_id.substr(pos+1, room_id.size() - pos);
            m.insert(make_pair(key, value));
        }
        
        // 截取预约状态
        pos = status.find(":");
        if(pos != -1)
        {
            key = status.substr(0, pos);
            value = status.substr(pos+1, status.size() - pos);
            m.insert(make_pair(key, value));
        }

        // 将小map放入大map中
        this->m_order_data.insert(make_pair(this->m_size, m));
        this->m_size++;
    }
    ifs.close();

    // 测试大map 
    // for(map<int, map<string, string> >::iterator it = m_order_data.begin(); it != m_order_data.end(); it++)
    // {
    //     cout << "key = " << it->first << "  value = " << endl;
    //     for(map<string, string>::iterator it1 = (*it).second.begin(); it1!= it->second.end(); it1++)
    //     {
    //         cout << it1->first << ": " << it1->second << "  ";
    //     }
    //     cout << endl;
    // }
}


// 更新预约记录
void OrderFile::update_order()
{
    if(this->m_size == 0)
    {
        return;
    }

    ofstream ofs("./example1/file/"+(string)ORDER_FILE, ios::out | ios::trunc);

    for(int i=0; i<this->m_size; i++)
    {
        ofs << "date:" << this->m_order_data[i]["date"] << "  ";
        ofs << "interval:" << this->m_order_data[i]["interval"] << "  ";
        ofs << "stu_id:" << this->m_order_data[i]["stu_id"] << "  ";
        ofs << "stu_name:" << this->m_order_data[i]["stu_name"] << "  ";
        ofs << "room_id:" << this->m_order_data[i]["room_id"] << "  ";
        ofs << "status:" << this->m_order_data[i]["status"] << endl;
    }
    ofs.close();
}

