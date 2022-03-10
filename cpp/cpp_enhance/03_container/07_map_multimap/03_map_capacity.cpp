#include<iostream>
using namespace std;
#include<map>

// map插入和删除

void print_map(map<int, int> &m)
{
    for(map<int, int>::iterator it = m.begin(); it !=m.end(); it++)
    {
        cout << "key=" << it->first << "\tvalue=" << it->second << endl;
    }
    cout << endl;
}

void test01()
{
    // 插入
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    
    // 不建议在插入中使用，多用于元素访问
    m[3] = 30;
    m[4] = 40;

    print_map(m);

    // cout << m[5] << endl;

    // 删除
    m.erase(m.begin());
    print_map(m);

    m.erase(3);     // 按照key值删除
    print_map(m);

    // m.erase(m.begin(), m.end());
    m.clear();
    print_map(m);
}

int main()
{
    test01();
    return 0;
}