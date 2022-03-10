#include<iostream>
using namespace std;
#include<set>

// set和multiset的区别

void test01()
{
    set<int> s;
    // set插入的时候会返回一个对组
    pair<set<int>::iterator, bool> ret = s.insert(10);      // pair是个对组，
    pair<set<int>::iterator, bool> ret2 = s.insert(10);

    if(ret.second){cout<<"插入成功"<<endl;}else{cout<<"插入失败"<<endl;}    // second表示对组的第二个元素
    if(ret2.second){cout<<"插入成功"<<endl;}else{cout<<"插入失败"<<endl;}


    multiset<int> ms;
    // multiset插入的时候会返回一个迭代器
    ms.insert(10);
    ms.insert(40);
    ms.insert(10);
    ms.insert(10);

    for(multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}

int main()
{
    test01();
    return 0;
}