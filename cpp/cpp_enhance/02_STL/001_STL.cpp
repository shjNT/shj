//容器、算法、迭代器初识

// vector容器存放内置数据类型


#include<iostream>
using namespace std;
#include<vector>

void my_print(int val)
{
    cout << val << endl;
}

void test01()
{
    vector<int> v;

    // 向容器中插入数据 
    for (int i=0; i<4; i++)
    {
        v.push_back(i * 10);
    }

    // 访问数据
    vector<int>::iterator it_begin = v.begin(); //起始迭代器，指向容器中第一个元素
    vector<int>::iterator it_end = v.end(); //结束迭代器，指向容器中最后一个元素的下一个位置
    // 遍历1：
    while(it_begin != it_end)
    {
        cout << (long)&it_begin << endl;
        cout << *it_begin << endl;
        it_begin++;
        
    }

    // 遍历2：-->> 常用
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    // 遍历3：STL中提供的遍历算法
    for_each(v.begin(), v.end(), my_print);

    
}

int main()
{
    test01();
    return 0;
}