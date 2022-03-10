#include<iostream>
using namespace std;
#include<list>

// list的赋值和交换


void print_list(const list<int> l)
{
    for(list<int>::const_iterator it = l.begin(); it !=l.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}


void test01()
{
    list<int> l1;
    for(int i =0; i<5; i++)
    {
        l1.push_back((i+1)*10);
    }
    print_list(l1);

    //赋值
    list<int> l2;
    l2 = l1;
    print_list(l2);

    list<int> l3;
    l3.assign(l2.begin(), l2.end());
    print_list(l3);

    list<int> l4;
    l4.assign(10, 100);
    print_list(l4);
}

// 交换
void test02()
{
    list<int> l1;
    for(int i =0; i<5; i++)
    {
        l1.push_back((i+1)*10);
    }
    print_list(l1);

    list<int> l2;
    l2.assign(10, 100);
    print_list(l2);

    l1.swap(l2);
    print_list(l1);
    print_list(l2);
}

int main()
{
    // test01();
    test02();
    return 0;
}