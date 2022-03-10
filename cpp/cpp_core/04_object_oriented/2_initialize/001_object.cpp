#include<iostream>
using namespace std;

// 构造函数和析构函数 ->> 对象的初始化和清理
// 编译器自动调用，用户定义，否则空实现

// 构造函数：类名(){}
/*
①没有返回值，不用写void
②函数名与类名相同
③构造函数可以有参数，可以发生重载
④创建对象时，构造函数会自动调用，而且只调用一次
*/

// 析构函数：~类名(){}
/*
①没有返回值，不用写void
②函数名与类名相同，要加~
③构造函数不可以有参数，不可以发生重载
④对象销毁前，析构函数会自动调用，而且只调用一次
*/

class Person
{
public:
    // 构造函数
    Person()
    {
        cout << "Person构造函数的调用" << endl;
    }

    // 析构函数
    ~Person()
    {
        cout << "Person析构函数的调用" << endl;
    }

};


int main(){

    Person p;
    system("read");
    return 0;
}