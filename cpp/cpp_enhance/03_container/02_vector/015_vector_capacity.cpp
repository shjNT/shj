#include <iostream>
using namespace std;
#include <vector>

// vector预留空间: 可减少vector在动态扩展容量时的扩展次数
// reserve(int len); 预留len个元素的长度，预留位置不初始化，元素不可访问

void test01()
{
    vector<int> v1;

    // 预留空间位置
    v1.reserve(100000);

    // 统计尾插100000个数据时，vector动态开辟了多少次内存
    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v1.push_back(i);

        if (p != &v1[0])
        {
            p = &v1[0];
            num++;
        }
    }
    cout << "num = " << num << endl;

    
    // cout << v1.capacity() << endl;
}

int main()
{
    test01();
    return 0;
}