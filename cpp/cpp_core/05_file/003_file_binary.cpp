#include<iostream>
using namespace std;
#include<fstream>

// 二进制文件

// 写：ostream& write(const char * buffer,int len);

// 读 read(char * buffer, int len)

class Person
{
public:
    char m_name[64];
    int m_age;
};

void test01()
{
    fstream fs;
    fs.open("person.txt", ios::in | ios::binary);
    if(!fs.is_open())
    {
        cout << "文件读取失败" << endl;
        return;
    }

    Person p;
    fs.read((char *) &p, sizeof(Person));
    cout << p.m_name << p.m_age << endl;
}

int main()
{
    // ofstream ofs;
    // ofs.open("person.txt", ios::out | ios::binary);
    // Person p={"sun", 18};
    // ofs.write((const char *)&p, sizeof(Person));
    // ofs.close();

    test01();

    return 0;
}