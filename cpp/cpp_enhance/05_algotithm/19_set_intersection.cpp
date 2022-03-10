// 常用集合算法
/*
1. set_intersection  容器交集
2. set_union   容器并集
3. set_difference   容器差集 
*/

#include<iostream>
using namespace std;
#include<numeric>
#include<vector>

// set_intersection(beg1, end1, beg2, end2, dest)
// 要求：原容器都是有序

void my_print(int val)
{
    cout << val << "  ";
}

void test01()
{
    vector<int> v1;
    vector<int> v2;

    vector<int> v_target;

    for(int i=0; i< 10 ; i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }

    v_target.resize(min(v1.size(), v2.size()));

    vector<int>::iterator it_end = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v_target.begin());

    for_each(v_target.begin(), it_end, my_print);
    cout << endl;

}

int main()
{
    test01();
    return 0;
}