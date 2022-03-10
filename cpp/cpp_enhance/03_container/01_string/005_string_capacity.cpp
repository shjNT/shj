#include<iostream>
using namespace std;

// string字符串比较
// 字符串的比较是按ASCII码进行对比(逐个对比)， =返回0；>返回1；<返回-1


void test01()
{
    string s1 = "hello";
    string s2 = "hello";
    int compare = s1.compare(s2);
    cout << compare << endl;

    string s3 = "xello";
    string s4 = "hello";
    int compare1 = s4.compare(s3);
    cout << compare1 << endl;

    string s5 = "aello";
    string s6 = "hello";
    int compare2 = s6.compare(s5);
    cout << compare2 << endl;
}

int main()
{
    test01();
    return 0;
}