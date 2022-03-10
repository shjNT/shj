#include<iostream>
using namespace std;

// string的查找和替换

// 查找
void test01()
{
    // 找到输出下标
     string s1 = "abcdefgde";
     int pos = s1.find("de");
     cout << "pos = " << pos << endl;

     // 找不到输出-1
     int pos1 = s1.find("deg");
     cout << "pos = " << pos1 << endl;

     // rfind ->>> 从右往左找
     int pos2 = s1.rfind("de");
     cout << "pos2 = " << pos2 << endl;
}

// 替换
void test02()
{
    string s = "abcdefg";
    s.replace(1, 3, "1");       // 从某个位置起，到某个位置，替换成指定的字符串
    cout << "s = " << s << endl;
}

int main()
{
    // test01();
    test02();
    return 0;
}