#include<iostream>
using namespace std;

// string字符串存取

void test01()
{
    string s = "hello world";
    cout << s[0] << endl;
    
    for (int i=0; i<(int)s.size(); i++)
    {
        cout << s[i] << endl;
    }

    for (int i=0; i<(int)s.size(); i++)
    {
        cout << s.at(i);
    }
    cout << endl;

    // 修改单个字符
    s[0] = 'x';
    cout << s << endl;
    s.at(1) = 'x';
    cout << s << endl;
}

int main()
{
    test01();
    return 0;
}