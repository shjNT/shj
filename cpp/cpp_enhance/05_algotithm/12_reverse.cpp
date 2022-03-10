#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

// reverse(iterator beg, end)

void my_print(int val)
{
    cout << val << "  ";
}


void test01()
{
    vector<int> v;
    for(int i=0; i< 10; i++)
    {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), my_print);
    cout << endl;

    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), my_print);
    cout << endl;
    
}

int main()
{
    test01();
    return 0;
}