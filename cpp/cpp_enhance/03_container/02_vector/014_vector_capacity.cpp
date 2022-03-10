#include<iostream>
using namespace std;
#include <vector>

// vector互换容器swap(vec) -->> 实现两个容器内的元素互换


void print_vector(vector<int> &v)
{
    for(vector<int>::iterator it =v.begin(); it !=v.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;
    for (int i=0; i<10; i++)
    {
        v1.push_back(i);
    }
    
    vector<int> v2;
    for (int i=10; i>0; i--)
    {
        v2.push_back(i);
    }
    
    cout << "交换前: " << endl;
    print_vector(v1);
    print_vector(v2);

    v1.swap(v2);
    cout << "交换后: " << endl;
    print_vector(v1);
    print_vector(v2);
}


// 实际用途：巧用swap可以收缩内存空间
void test02()
{
    vector<int> v;
    for (int i=0; i<100000; i++)
    {
        v.push_back(i);
    }

    cout << "v的容量: " << v.capacity() << endl;
    cout << "v的大小: " << v.size() << endl;

    v.resize(3);
    cout << "v的容量: " << v.capacity() << endl;
    cout << "v的大小: " << v.size() << endl;


    // 巧用swap收缩内存
    vector<int> (v).swap(v);    // vector<int> (v) -->> 匿名对象
    cout << "v的容量: " << v.capacity() << endl;
    cout << "v的大小: " << v.size() << endl;

}


int main()
{
    // test01();
    test02();
    return 0;
}