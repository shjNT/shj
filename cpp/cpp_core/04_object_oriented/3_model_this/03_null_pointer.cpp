#include<iostream>
using namespace std;

// 空指针访问成员函数


class Person
{
public:
    void show_name()
    {
        cout << "this is person class" << endl;
    }

    void show_age()
    {   
        if(this == NULL)
        {
            return;
        }
        cout << "age = " << this->m_age << endl;
    }

    int m_age;

};

void test01(){
    Person * p = NULL;

    p ->show_age();
    // p->show_name();
}

int main()
{
    test01();

    return 0;
}