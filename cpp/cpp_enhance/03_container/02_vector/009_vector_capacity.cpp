// vector 容器 -->> 单端数组
// vector相较于数组，其可以动态扩展 -->> 不是在原有的基础上扩展，而是找到更大的空间，再将原来的数据拷贝进来
// vector的迭代器是支持随机访问的迭代器


#include<iostream>
using namespace std;
#include <vector>


// vector的构造函数

void print_vector(vector<int> &v)
{
    for (vector<int>::iterator it =v.begin(); it < v.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}

void test01()
{
    // 无参构造
    vector<int> v1;
    for (int i=0; i<10; i++)
    {
        v1.push_back(i);
    }
    print_vector(v1);

    // 通过区间方式
    // vector<int> v2(v1.begin(), v1.end());
    // print_vector(v2);

    // n element
    vector<int> v3(10, 1);
    print_vector(v3);

    vector<int> v4(v3);
    print_vector(v4);

}

int main()
{

    test01();
    return 0;
}