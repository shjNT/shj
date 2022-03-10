#include<iostream>
using namespace std;

// string中的插入和删除

void test01()
{
    // 插入
    string s = "hello";
    s.insert(1, "kkkk");
    cout << "s = " << s << endl;

    // 删除
    s.erase(1, 4);
    cout << "s = " << s << endl;
}

int main()
{
    test01();
    return 0;
}