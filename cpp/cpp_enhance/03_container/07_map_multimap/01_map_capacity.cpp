// map/multimap基本概念
/*
① map中所有元素都是pair;
② pair中的第一个元素为key，第二个元素为value
③ 所有元素会根据元素的key值自动排序
④ 关联式容器，底层结构是二叉树
⑤ map中不允许重复key，multimap允许重复key
*/


#include<iostream>
using namespace std;
#include<map>

void print_map(map<int, int> &m)
{
    for(map<int, int>::iterator it = m.begin(); it !=m.end(); it++)
    {
        cout << "key = " << (*it).first << "\tvalue = " << (*it).second << endl;
    }
}

void test01()
{
    // 创建map容器
    map<int, int> mp;

    // 插数据
    mp.insert(pair<int, int>(1, 10));
    mp.insert(pair<int, int>(2, 20));
    mp.insert(pair<int, int>(4, 40));
    mp.insert(pair<int, int>(3, 30));
    mp.insert(pair<int, int>(4, 40));

    print_map(mp);

    // 拷贝构造
    map<int, int> m2(mp);
    print_map(m2);

    // 赋值
    map<int, int>m3;
    m3=m2;
    print_map(m3);
}


int main()
{
    test01();
    return 0;
}