#include<iostream>
using namespace std;
#include <set>

// set的插入和删除

void print_set(const set<int> s)
{
    for(set<int>::const_iterator it = s.begin(); it !=s.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;
    s1.insert(40);
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);

    print_set(s1);

    // 删除
    s1.erase(s1.begin());
    print_set(s1);

    s1.erase(20);
    print_set(s1);

    // 清空
    s1.clear();
    print_set(s1);
}

int main()
{
    test01();
    return 0;
}