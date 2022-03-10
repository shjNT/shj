#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// replace_if(iterator beg, end, _Pred, newvalue);

class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << "  ";
    }
};

class Greater30
{
public:
    bool operator()(int val)
    {
        return val >= 30;
    }
};

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(90);

    cout << "替换前: " << endl;
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;

    // 大于30的替换为3000
    replace_if(v.begin(), v.end(), Greater30(), 3000);

    cout << "替换后: " << endl;
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}

int main()
{
    test01();
    return 0;
}