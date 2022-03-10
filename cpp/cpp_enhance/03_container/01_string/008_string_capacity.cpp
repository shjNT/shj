#include<iostream>
using namespace std;

// string子串 -->> 截取子串substr


void test01()
{
    string s = "abcdef";
    string sub_s = s.substr(1, 3);  // 从pos起，截取多少个
    cout << sub_s << endl;
}

void test02()
{
    string em = "1044444@dake.com";
    int idx = em.find("@");
    string sub_s = em.substr(0, idx);  // 从pos起，截取多少个
    cout << sub_s << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}