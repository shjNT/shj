#include<iostream>
using namespace std;

// 类对象作为类成员
// c++中类的成员可以是另一个类的对象，该成员称为对象成员


class Phone
{
public:
    Phone(string pname)
    {
        p_name = pname;
        cout << "phone构造" << endl;
    }
    ~Phone()
    {
        cout << "phone析构" << endl;
    }
    string p_name;
};

class Person
{

public:
    Person(string name, string pname): m_name(name), m_phone(pname)
    {
        cout << "person构造" << endl;
    }

    ~Person(){
        cout << "person析构" << endl;
    }
    string m_name;
    Phone m_phone;
};

void test01()
{
    Person p("sun", "huawei");
    cout << p.m_name << "拿着" << p.m_phone.p_name << "手机" << endl;
};

int main()
{
    test01();
    return 0;
}

// 结论：当其他类作为本类成员时，构造时先构造类对象成员，再构造自身，析构顺序相反