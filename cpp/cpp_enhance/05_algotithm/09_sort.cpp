// 常用排序算法
/*
1. sort  ---  对容器内元素进行排序
2. random_shuffle  ---  洗牌 指定范围内的元素随机调整次序
3. merge  ---  容器元素合并，并存储到另一容器中
4. reverse  ---   反转指定范围元素 
*/


#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<functional>


// sort(iterator beg, end, _Pred)

void my_print(int val)
{
    cout << val << "  ";
}

void test01()
{
    vector<int> v;
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(0);

    sort(v.begin(), v.end());
    
    for_each(v.begin(), v.end(), my_print);
    cout << endl;

    // 降序
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), my_print);
    cout << endl;
}

int main()
{
    test01();
    return 0;
}