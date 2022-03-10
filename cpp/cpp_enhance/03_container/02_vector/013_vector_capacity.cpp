#include<iostream>
using namespace std;
#include <vector>


// vector数据存储


void test01()
{
    vector<int> v1;
    for (int i= 0; i<10; i++)
    {
        v1.push_back(i);
    }

    // []访问
    for (int i= 0; i<(int)v1.size(); i++)
    {
        cout << v1[i] << "  ";
    }
    cout << endl;

    // at访问
    for (int i= 0; i<(int)v1.size(); i++)
    {
        cout << v1.at(i) << "  ";
    }
    cout << endl;

    // 获取第一个元素
    cout << v1.front() << endl;

    //获取最后一个元素
    cout << v1.back() << endl;
}

int main()
{   
    test01();
    return 0;
}