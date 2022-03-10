#include <iostream>
using namespace std;
#include <vector>

//vector的插入和删除
/*
① push_back(ele);   尾插
② pop_back();       尾删
③ insert(const_iterator pos, ele);  迭代器指向位置pos插入ele
④ insert(const_iterator pos, int count ele)
⑤ erase(const_iterator pos); 删除迭代器指向的元素；
⑥ erase(const_iterator start, const_iterator end);
⑦ clear();  删除所有元素
*/


void print_vector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin(); it < v.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}


void test01()
{
    vector<int> v1;
    // 尾插
    for(int i=1; i<6; i++)
    {
        v1.push_back(i * 10);
    }
    print_vector(v1);

    // 尾删
    v1.pop_back();
    print_vector(v1);

    //insert
    v1.insert(v1.begin(), 4);
    print_vector(v1);

    v1.insert(++v1.begin(), 2, 88);
    print_vector(v1);

    // erase
    v1.erase(v1.begin());
    print_vector(v1);

    // 清空
    // v1.erase(v1.begin(), v1.end());
    v1.clear();
    print_vector(v1);
}

int main()
{
    test01();
    return 0;
}