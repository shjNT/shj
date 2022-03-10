// 谓词
/*
①返回bool类型的仿函数称为谓词
②若operator()接受一个参数，称为一元谓词
③若operator()接受两个参数，称为二元谓词
*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 一元谓词

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 查找容器中大于5的数字
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive()); // GreaterFive() 匿名函数对象
    if (it == v.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到了: " << (*it) << endl;
    }
}

int main()
{
    test01();
    return 0;
}