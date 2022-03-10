// deque容器 -->>双端数组

// deque与vector区别：deque头部操作快；vector访问员速快
// deque容器的迭代器也是支持随机访问的
 

#include<iostream>
using namespace std;
#include<deque>

// deque构造函数


void print_deque(const deque<int> &d)
{
    // const 限定只读
    for(deque<int>::const_iterator it = d.begin(); it !=d.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

void test01()
{
    deque<int> d1;
    for (int i=0; i< 10; i++)
    {
        d1.push_back(i);
    }
    print_deque(d1);


    deque<int> d2(d1.begin(), d1.end());
    print_deque(d2);


    deque<int> d3(10, 100);
    print_deque(d3);

    deque<int> d4(d3);
    print_deque(d4);
}

int main()
{
    test01();
    return 0;
}