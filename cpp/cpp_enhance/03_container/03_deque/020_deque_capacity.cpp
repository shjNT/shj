#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

// deque 排序

void print_deque(const deque<int> &d)
{
    for(deque<int>::const_iterator it=d.begin(); it!=d.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}


void test01()
{
    deque<int> d1;
    for (int i=0; i<10; i++)
    {
        d1.push_front(i);

    }
    for (int i=2; i<4; i++)
    {
        d1.push_back(i);
    }
    print_deque(d1);

    // 对于支持随机访问的迭代器容器，都可以利用sort算法对其进行直接排序
    // sort排序
    sort(d1.begin(), d1.end());
    print_deque(d1);
}

int main()
{
    test01();
    return 0;
}