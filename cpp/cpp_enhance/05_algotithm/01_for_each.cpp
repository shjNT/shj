#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// for_each // 遍历容器

// 普通函数
void print01(int val)
{
    cout << val << "  ";
}

// 仿函数
class Print02
{
public:
    void operator()(int val)
    {
        cout << val << "  ";
    }
    
};


void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    for_each(v1.begin(), v1.end(), print01);
    cout << endl;

    for_each(v1.begin(), v1.end(), Print02());  //仿函数需要放函数对象 
    cout << endl;
}

int main()
{
    test01();
    return 0;
}