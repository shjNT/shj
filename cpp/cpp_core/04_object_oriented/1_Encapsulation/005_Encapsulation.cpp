#include<iostream>
using namespace std;

// 成员属性设置为私有
// 好处：①控制读写权限；②对于写可以检测数据的有效性

class Person
{
public:
    void set_name(string s_name)
    {
        name = s_name;
    };
    string get_name()
    {
        return name;
    };

    // 可读可写，若修改年龄，范围为0~150
    int get_age()
    {
        // age = 0;
        return age;
    };

    void set_age(int s_age)
    {
        if(s_age < 0 || s_age > 150)
        {
            age = 0;
            cout << "年龄不合理" << endl;
            return;
        }
        age = s_age;
    }

    void set_lover(string s_lover)
    {
        lover = s_lover;
    };

private:
    string name; //可读可写
    int age;    //只读
    string lover;   //只写

};

int main(){

    Person p1;
    p1.set_name("sun");
    cout << "name: " << p1.get_name() << endl;

    p1.set_age(10);
    cout << "age: " << p1.get_age() << endl;

    p1.set_lover("wql");
    return 0;
}