// set 集合容器 -->> 所有元素在插入时自动被排序

// set/multiset属于关联式容器，底层结构是用二叉树实现
// 区别：set不允许有重复元素， multiset允许有重复元素


#include<iostream>
using namespace std;
#include<set>

// set构造和赋值


void print_set(const set<int> &s)
{
    for(set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << (*it) << " ";
    }
    cout << endl;
}


void test01()
{
    set<int> s1;

    //插入数据，只有insert
    s1.insert(10);
    s1.insert(20);
    s1.insert(50);
    s1.insert(30);
    s1.insert(40);
    s1.insert(30);
    // set容器特点：默认排序，重复值去重
    print_set(s1);

    set<int> s2(s1);
    print_set(s2);
    
    set<int> s3;
    s3 = s2;
    print_set(s3);
}

int main()
{
    test01();
    return 0;
}