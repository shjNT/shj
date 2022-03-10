#include<iostream>
using namespace std;
#include<functional>
#include<vector>
#include<algorithm>

// 内建函数对象 --- 关系仿函数
// 大于greater

void test01()
{
    vector<int> v;
    v.push_back(40);
    v.push_back(20);
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);

    for(vector<int>::iterator it = v.begin(); it !=v.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());   //greater<int>()内建仿函数>

    for(vector<int>::iterator it = v.begin(); it !=v.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}

int main()
{
    test01();
    return 0;
}