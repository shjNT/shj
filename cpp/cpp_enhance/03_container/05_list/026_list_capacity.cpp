#include<iostream>
using namespace std;
#include<list>

// list大小操作

void print_list(const list<int> &l)
{
    for(list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}

void test01()
{
    list<int> l1;
    list <int> l2;
    for(int i = 0; i< 5; i++)
    {
        l1.push_back((i+1)*10);
    }
    print_list(l1);

    if (l2.empty()){cout<<"空"<<endl;}else{cout<<"不空"<< endl;}

    cout << l1.size() << endl;

    l1.resize(20);
    print_list(l1);
    l1.resize(1);
    print_list(l1);

}

int main()
{
    test01();
    return 0;
}