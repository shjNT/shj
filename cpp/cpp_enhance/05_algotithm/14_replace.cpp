#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

// replace
// replace(iterator bef, end, oldevalue, newvalue)

void my_print(int val)
{
    cout << val << "  ";
}

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);

    cout << "替换前: " << endl;
    for_each(v.begin(), v.end(), my_print);
    cout << endl;

    replace(v.begin(), v.end(), 20, 20000);

    cout << "替换后: " << endl;
    for_each(v.begin(), v.end(), my_print);
    cout << endl;

}

int main()
{
    test01();
    return 0;
}