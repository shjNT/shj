#include<iostream>
using namespace std;
#include<list>

//list插入和删除

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
    list<int> l1;
    
    // 尾插
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);

    // 头插
    l1.push_front(100);
    l1.push_front(200);
    l1.push_front(300);

    print_list(l1);

    // 尾删
    l1.pop_back();
    print_list(l1);

    // 头删
    l1.pop_front();
    print_list(l1);

    // insert插入
    list<int>::iterator it = ++l1.begin();
    l1.insert(it, 90);
    print_list(l1);

    // 删除
    it = l1.begin()++;
    l1.erase(it);
    print_list(l1);

    //移除remove
    l1.remove(100);
    print_list(l1);

    l1.assign(4, 1000);
    print_list(l1);
    // l1.remove(1000);
    // print_list(l1);

    // clear
    l1.clear();
    print_list(l1);
}

int main()
{
    test01();
    return 0;
}