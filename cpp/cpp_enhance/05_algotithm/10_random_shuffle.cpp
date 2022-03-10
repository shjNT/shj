#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <ctime>

// random_shuffle(iterator beg, end)  ?????????????????

void my_print(int val)
{
    cout << val << "  ";
}

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    random_shuffle(v.begin(), v.end());

    for_each(v.begin(), v.end(), my_print);
    cout << endl;
}

int main()
{
    srand((unsigned int)time(NULL));
    test01();
    return 0;
}