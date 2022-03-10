#include<iostream>
using namespace std;
#include<map>

// map查找和统计 
// find(key) 查找key是否存在，若存在返回该key元素的迭代器，若不存在，返回map.end()
// count(key) 统计key元素个数-> 0或1

void test01()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    map<int, int>::iterator it = m.find(3);
    if(it != m.end())
    {
        cout << "找到元素, key=" << it->first << "  value=" << it->second << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }

    // 统计
    int num = m.count(3);
    cout << num << endl;
    int num1 = m.count(4);
    cout << num1 << endl;
}

int main()
{
    test01();
    return 0;
}