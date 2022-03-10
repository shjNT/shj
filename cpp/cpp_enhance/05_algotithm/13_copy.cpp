// 常用的拷贝和替换算法
/*
1.copy  ---  容器内指定范围的元素拷贝到另一容器
2.replace   ---    将容器内指定范围的旧元素修改为新元素
3.replace_if    ---    容器内指定范围满足条件的元素替换为新元素
4.swap
*/

#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

// copy(iterator beg, end, iterator dest);

void my_print(int val)
{
    cout << val << "  ";
}

void test01()
{
    vector<int> v;
    for(int i =0; i<5; i++)
    {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), my_print);
    cout << endl;

    vector<int> v2;
    v2.resize(v.size());

    copy(v.begin(), v.end(), v2.begin());
    for_each(v2.begin(), v2.end(), my_print);
    cout << endl;
}

int main()
{
    test01();
    return 0;
}