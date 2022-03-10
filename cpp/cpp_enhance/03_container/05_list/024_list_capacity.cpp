// list容器 -->> 链表 -->> 双向循环链表

// 链表： 结点(数据域+指针域)
// 链表迭代器：双向迭代器

#include<iostream>
using namespace std;
#include <list>

// 构造

void print_list(const list<int> &l)
{
    for(list<int>::const_iterator it = l.begin(); it!=l.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}

void test01()
{
    // 默认构造
    list<int> l1;

    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    print_list(l1);

    // 区间构造
    list<int> l2(l1.begin(), l1.end());
    print_list(l2);

    // 拷贝构造
    list<int> l3(l2);
    print_list(l3);

    // n个elem
    list<int> l4(4, 5);
    print_list(l4);
}

int main()
{
    test01();
    return 0;
}