#include<iostream>
using namespace std;
#include<set>

// set大小和交换


void print_set(const set<int> &s)
{
    for(set<int>::const_iterator it = s.begin(); it !=s.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}

// 大小
void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(40);
    s1.insert(20);
    s1.insert(12);
    print_set(s1);
    cout << s1.size() << endl;

    if (s1.empty())
    {
        cout << "空" << endl;
    }else {cout << "不空" << endl;}
}

// 交换
void test02()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(40);
    s1.insert(20);
    s1.insert(12);
    print_set(s1);

    set<int> s2;
    for(int i =0 ; i<5; i++)
    {
        s2.insert(i);
    }
    print_set(s2);

    s1.swap(s2);
    cout << "======交换后======" << endl;
    print_set(s1);
    print_set(s2);

}

int main()
{
    // test01();
    test02();
    return 0;
}
