#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

// adjacent_find(iterator beg, end)
// 查找相邻重复元素，返回相邻元素的第一个位置的迭代器


void test01()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(4);
    v.push_back(3);

    vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
    if(pos == v.end())
    {
        cout << "没找到" << endl;
    }
    else
    {
        cout << "找到: " << (*pos) << endl;
    }
}

int main()
{
    test01();
    return 0;
}