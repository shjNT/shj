#include<iostream>
using namespace std;
#include<list>
#include<algorithm>

// list反转和排序
// ①反转列表reverse； ②sort;


void print_list(const list<int> &l)
{
    for(list<int>::const_iterator it=l.begin(); it !=l.end(); it++)
    {
        cout<< (*it) <<"  ";
    }
    cout << endl;
}


// 反转
void test01()
{
    list<int> l;
    l.push_back(34);
    l.push_back(24);
    l.push_back(44);
    l.push_back(2);

    print_list(l);
    
    l.reverse();
    print_list(l);
}


// 仿函数
bool my_compare(int v1, int v2)
{
    // 降序：
    return v1 > v2;
}


// 排序
void test02()
{   
    list<int> l;
    l.push_back(34);
    l.push_back(24);
    l.push_back(44);
    l.push_back(2);
    print_list(l);

    // 所有不支持随机访问迭代器的容器，不可以用标准算法
    // sort(l.begin(), l.end());
    // print_list(l);

    // 不支持随机访问迭代器的容器，内部会提供相应的算法
    l.sort();   // 默认升序
    print_list(l);
    // 降序
    l.sort(my_compare);
    print_list(l);
}

int main()
{
    // test01();
    test02();
    return 0;
}