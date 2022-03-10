#include<iostream>
using namespace std;
#include<deque>

// deque大小操作

void print_deque(const deque<int> &d)
{
    for(deque<int>::const_iterator it = d.begin(); it !=d.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}

void test01()
{
    deque<int> d1;
    for(int i=0;i< 10;i++)
    {
        d1.push_back(i);
    }
    print_deque(d1);

    // 判断空？
    if(d1.empty()){cout << "d1为空" <<endl;}else{cout << "d1不为空" << endl;}

    // 大小
    cout << d1.size() << endl;

    // 重新指定大小
    d1.resize(15);
    print_deque(d1);

    d1.resize(5);
    print_deque(d1);
}

int main()
{
    test01();
    return 0;
}