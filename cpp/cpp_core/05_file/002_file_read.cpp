#include<iostream>
using namespace std;
#include<fstream>

// 读文件

void test01()
{
    fstream fs;
    fs.open("./test.txt", ios::in);
    //判断是否打开成功
    if(!fs.is_open())
    {
        cout << "打开失败" << endl;
        return;
    }

    //读数据
    // ①
    // char buf[1024] = {0};
    // while(fs >> buf)
    // {
    //     cout << buf << endl;
    // }
    // ②
    // char buf[1024] = {0};
    // while(fs.getline(buf, sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }

    // ③ 推荐
    string buf;
    while(getline(fs, buf))
    {
        cout << buf << endl;
    }

    // ④ 不推荐
    // char c;
    // while((c = fs.get()) !=EOF) // EOF ->end of file: 文件尾
    // {
    //     cout<< c;
    // }
    // fs.close();
}

int main()
{
    test01();
    return 0;
}