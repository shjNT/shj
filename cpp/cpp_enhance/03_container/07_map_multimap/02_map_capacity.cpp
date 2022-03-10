#include<iostream>
using namespace std;
#include<map>

// map的大小和交换size；empty； swap


void print_map(map<int, int> &m)
{
    for(map<int, int>::iterator it = m.begin(); it !=m.end(); it++)
    {
        cout << "key=" << it->first <<"\tvalue=" << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    if(m.empty()){cout<<"空"<<endl;}else{cout<<"不空"<<endl; cout<<m.size()<<endl;}

    map<int, int> m2;
    m2.insert(pair<int, int>(4, 100));
    m2.insert(pair<int, int>(5, 200));
    m2.insert(pair<int, int>(6, 300));

    cout << "交换前" << endl;
    print_map(m);
    print_map(m2);

    m.swap(m2);
    cout << "交换后" << endl;
    print_map(m);
    print_map(m2);
}

int main()
{
    test01();
    return 0;
}