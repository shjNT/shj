#include <iostream>
using namespace std;
#include <vector>

// vector赋值操作

void print_vector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    print_vector(v1);

    // 赋值
    vector<int> v2 = v1;
    print_vector(v2);

    vector<int> v3;
    // v3.assign(v1.begin(), v1.end());
    // print_vector(v3);

    vector<int> v4;
    v4.assign(10, 100);
    print_vector(v4);
}

int main()
{
    test01();
    return 0;
}