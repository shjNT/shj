#include<iostream>
using namespace std;
#include<set>

// set查找和统计 
//find(); 返回元素的迭代器 ，不存在返回end
//cout(); 返回0或1


// 查找
void test01()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    set<int>::iterator pos = s1.find(20);
    if(pos != s1.end()){cout <<"找到:"<<(*pos)<<endl;}else{cout<<"没找到"<<endl;}
}

// 统计
void test02()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    int num = s1.count(30);       // 统计30的个数
    cout << num << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}