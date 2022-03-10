// 内建函数对象
// 概念: STL内建了一些函数对象
// 分类: ①算术仿函数；②关系仿函数；③逻辑仿函数
// 用法：引入头文件 <functional>; 仿函数用法



#include<iostream>
using namespace std;
#include<functional>

// 算术仿函数 plus加法; negate取反

void test01()
{
    negate<int> n;
    cout << n(50) << endl;
}

void test02()
{
    plus<int> p;
    cout << p(10, 30) << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}