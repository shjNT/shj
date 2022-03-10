#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

// merge 两个容器元素合并，并存储到另一容器中
// merge(iterator beg1, iterator end1, iteartor beg2, iterator end2, iterator dest);
// 要求：两个容器必须是有序的，合并后依然是有序的


void my_print(int val)
{
    cout << val << "  ";
}

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for(int i=0; i<10; i++)
    {
        v1.push_back(i);
        v2.push_back(i*2);
    }

    vector<int> v_target;
    v_target.resize(v1.size()+v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v_target.begin());

    for_each(v_target.begin(), v_target.end(), my_print);
    cout << endl;
}

int main()
{
    test01();
    return 0;
}