#include<iostream>
using namespace std;
#include<fstream>   // 对文件操作要包含头文件<fstream>

// 文件操作
// 操作文件的三大类：①ofstream 写；②ifstream 写；③ fstream 读写；

// 文本文件
/*
步骤：
    ①包含头文件 #include<fstream>
    ②创建流对象 ofstream ofs；
    ③打开文件 ofs.open("路径"，打开方式)；
    ④写数据 ofs<<"写入的数据";
    ⑤关闭文件 ofs.close();
*/

/*
文件打开方式：
① ios::in   为读文件而打开文件；
② ios::out  为写文件而打开文件；
③ ios::ate  初识位置为文件尾；
④ ios::app  追加方式写文件；
⑤ ios::binary   二进制方式；

注意：文件打开方式可以配合使用，利用|操作符
*/

void test01()
{
    ofstream ofs;
    ofs.open("./test.txt", ios::out);
    ofs<<"姓名: 孙" << endl;
    ofs<<"年龄: 18" << endl;
    ofs<<"性别: 男" << endl;
    ofs.close();

    fstream fs;
    fs.open("./test.txt", ios::app);
    fs << "dream: sleeping" << endl;
    fs.close();
}

int main()
{
    test01();

    return 0;
}