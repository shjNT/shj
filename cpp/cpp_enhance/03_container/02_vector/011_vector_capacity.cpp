#include<iostream>
using namespace std;
#include <vector>

// vector的容量和大小操作


void print_vector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}


void test01()
{
    vector<int> v1;
    for (int i=0;i < 10; i++)
    {
        v1.push_back(i);
    }
    print_vector(v1);

    int a = v1.empty();     // 真代表空，假代表不为空
    cout << a << endl;   

    int ca = v1.capacity();
    cout << "v1的容量: " << ca << endl;

    int si = v1.size();
    cout << "v1的大小: " << si << endl;

    // 重新指定大小, 若比原来长，用0填充，也可指定
    v1.resize(15);
    print_vector(v1);
    v1.resize(18, 100);
    print_vector(v1);

    // 若比原来短，后面的被删除
    v1.resize(5);
    print_vector(v1);
    cout << v1.capacity() << endl;
}

int main()
{
    test01();
    return 0;
}