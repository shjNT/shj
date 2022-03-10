// string本质：
// string是一个类，类内部封装了char*，管理这个字符串，是一个char*型的容器


#include<iostream>
using namespace std;

// string的构造函数

void test01()
{
    string s1;  // ①默认构造

    // ②使用字符串初始化
    const char * str = "hello world";
    string s2(str);
    cout << "s2 = " << s2 << endl;

    // ③拷贝构造
    string s3(s2);
    cout << "s3 = " << s3 << endl;

    // ④n个字符组成字符串
    string s4(10, 'a');
    cout << "s4 = " << s4 << endl;

}


int main()
{
    test01();
    return 0;
}