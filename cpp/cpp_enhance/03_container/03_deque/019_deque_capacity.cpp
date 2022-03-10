#include<iostream>
using namespace std;
#include<deque>

// deque数据访问

void print_deque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}

void test01()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    //[]访问
    for(int i=0; i<(int)d.size(); i++)
    {
        cout << d[i] << "  ";
    }
    cout << endl;

    // at访问
    for(int i=0; i<(int)d.size(); i++)
    {
        cout << d.at(i) << "  ";
    }
    cout << endl;

    // 第一个元素
    cout << d.front()<< endl;
    // 最后一个元素
    cout << d.back() << endl;
}

int main()
{
    test01();
    return 0;
}