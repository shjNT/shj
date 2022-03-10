#include<iostream>
using namespace std;

// pair对组创建 -->> 成对出现的数据

void test01()
{
    pair<string, int> p("sun", 20);
    cout << p.first << p.second << endl;

    pair<string, int> p2 = make_pair("sun", 50);
    cout << p2.first << p2.second << endl;
}

int main()
{
    test01();
    return 0;
}