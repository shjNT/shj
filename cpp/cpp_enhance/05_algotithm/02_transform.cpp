#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

// transform:搬运容器至另一个容器
// 语法：
// transform(iterator beg1, iterator end1, iterator beg2, _func)


class Transform
{
public:
    int operator()(int v)
    {
        return v;
    }
};

class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val+100 << "  ";
    }
};


void test01()
{
    vector<int> v;
    for(int i =0 ; i< 10; i++)
    {
        v.push_back(i);
    }

    vector<int> v_target;
    v_target.resize(v.size());  // 目标容器需要开辟空间
    transform(v.begin(), v.end(), v_target.begin(), Transform());

    for_each(v_target.begin(), v_target.end(), MyPrint());
    cout << endl;
}

int main()
{
    test01();
    return 0;
}