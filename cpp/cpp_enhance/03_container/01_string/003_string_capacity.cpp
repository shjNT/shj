#include<iostream>
using namespace std;

// string字符串拼接


void test01()
{
    string s1 = "i";
    s1 += " love play game";
    cout << s1 << endl;

    s1 += ':';
    cout << s1 << endl;

    string s2 = " lol";
    s1 += s2;
    cout << s1 << endl;

    string s3 = "you";
    s3.append(" lov me");
    cout << s3 << endl;

    s3.append("caaaaa", 1);     //拼接截取前4个
    cout << s3 << endl;

    s3.append(s2);
    cout << s3 << endl;

    s3.append(s2, 0, 2);    //拼接时，从某个位置开始，截取多少个
    cout << s3 << endl;
}


int main()
{
    test01();
    return 0;
}