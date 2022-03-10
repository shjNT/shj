// 常用算术生成算法
// 包含头文件#include<numeric>

/*
1. accumulate   计算容器元素累计总和
2. fill     向容器内添加元素
*/

#include<iostream>
using namespace std;
#include<vector>
#include<numeric>

// accumulate(iterator beg, end, value);    value为起始值

void test01()
{
    vector<int> v;

    for(int i =0; i<=100; i++)
    {
        v.push_back(i);
    }

    int total = accumulate(v.begin(), v.end(), 10);
    cout << total << endl;
}

int main()
{
    test01();
    return 0;
}