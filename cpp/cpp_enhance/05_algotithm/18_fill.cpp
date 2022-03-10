#include<iostream>
using namespace std;
#include<numeric>
#include<vector>

// fill()

void my_print(int val)
{
    cout << val << "  ";
}

void test01()
{
    vector<int> v;
    v.resize(10);

    fill(v.begin(), v.end(), 1000);

    for_each(v.begin(), v.end(), my_print);
    cout << endl;
}

int main()
{
    test01();
    return 0;
}