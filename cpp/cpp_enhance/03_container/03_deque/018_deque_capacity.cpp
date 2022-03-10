#include <iostream>
using namespace std;
#include <deque>

// deque插入和删除

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
    deque<int> d1;

    //尾插
    d1.push_back(10);
    d1.push_back(20);

    //头插
    d1.push_front(100);
    d1.push_front(200);

    // 尾删
    d1.pop_back();

    // 头删
    d1.pop_front();
    print_deque(d1);
}

void test02()
{
    deque<int> d2;
    for(int i =0; i<5; i++)
    {
        d2.push_front(i);
    }
    print_deque(d2);

    // 指定插
    d2.insert(d2.begin(), 100);
    print_deque(d2);
    d2.insert(d2.end(), 2, 89);
    print_deque(d2);
}

void test03()
{
    deque<int> d3;
    for (int i=0; i< 8; i++)
    {
        d3.push_front(i);
    } 
    print_deque(d3);

    // 删除
    deque<int>::iterator it = d3.begin();
    it++;
    d3.erase(it);
    print_deque(d3);

    // 清空
    d3.clear();
    print_deque(d3);
}


int main()
{

    // test01();
    // test02();
    test03();
    return 0;
}