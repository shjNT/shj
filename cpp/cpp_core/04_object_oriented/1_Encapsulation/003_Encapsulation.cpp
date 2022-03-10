#include<iostream>
using namespace std;

// 访问权限
// ① public 公共权限       ->    成员类内可以访问，类外可以访问
// ② protected  保护权限   ->    成员类内可以访问，类外不可以访问   子类可以访问
// ③ private 私有权限      ->    成员类内可以访问，类外不可以访问   子类不可以访问


class Person
{
public:
    string name;  //公共权限

protected:
    string car;  // 保护权限

private:
    int password;  // 私有权限

public:
    void func()
    {
        name = "sun";
        car = "tsl";
        password = 119;
    };

};

int main(){
    Person p1;
    p1.name = "zhao";
    // p1.car = "byd";    //保护权限类外不可访问
    // p1.password = 123; //私有权限类外不可访问

    p1.func();
    return 0;
}