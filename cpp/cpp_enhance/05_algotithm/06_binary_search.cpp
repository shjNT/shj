#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

// binary_search(iterator beg, end, val)
// 注：必须为有序序列， 若为无序，结果错


void test01()
{
    vector<int> v;
    for(int i =0 ;i < 10; i++)
    {
        v.push_back(i);
    }
    
    bool ret = binary_search(v.begin(), v.end(), 9);

    if (ret) {cout << "找到" << endl;} else{cout << "没找到" << endl;}
}

int main()
{
    test01();
    return 0;
}