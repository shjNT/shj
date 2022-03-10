#include<iostream>
using namespace std;
#include<list>

// 数据访问 front；back

void print_list(const list<int> &l)
{
    for (list<int>::const_iterator it = l.begin(); it !=l.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}

void test01()
{
    list<int> l;
    for (int i=0; i< 10; i++)
    {
        l.push_back(i+1);
    }
    print_list(l);

    cout << l.front() << endl;
    cout << l.back() << endl;

    // 验证迭代器是不支持随机访问的
    list<int>::iterator it = l.begin();
    it++; 
    it--;   // 只支持双向
    // it = it + 1; // 不支持随机访问
}

int main()
{
    test01();
    return 0;
}