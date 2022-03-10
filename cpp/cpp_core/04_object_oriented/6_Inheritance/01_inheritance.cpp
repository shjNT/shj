#include<iostream>
using namespace std;

// 继承

// 语法：  class 子类 : 继承方式 父类


// class Java
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录、注册 ... (公共头部)" << endl;
//     }

//     void footer()
//     {
//         cout << "帮助中心、交流合作、站内地图 ... (公共底部)" << endl;
//     }

//     void left()
//     {
//         cout << "Java、Python、C++ ... (公共分类列表)" << endl;
//     }

//     void content()
//     {
//         cout << "Java学科vido" << endl;
//     }
// };

// class Python
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录、注册 ... (公共头部)" << endl;
//     }

//     void footer()
//     {
//         cout << "帮助中心、交流合作、站内地图 ... (公共底部)" << endl;
//     }

//     void left()
//     {
//         cout << "Java、Python、C++ ... (公共分类列表)" << endl;
//     }

//     void content()
//     {
//         cout << "Python学科vedio" << endl;
//     }
// };

// class Cpp
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录、注册 ... (公共头部)" << endl;
//     }

//     void footer()
//     {
//         cout << "帮助中心、交流合作、站内地图 ... (公共底部)" << endl;
//     }

//     void left()
//     {
//         cout << "Java、Python、C++ ... (公共分类列表)" << endl;
//     }

//     void content()
//     {
//         cout << "C++学科vido" << endl;
//     }
// };


// 继承实现

// 公共页面类
class BasePage
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册 ... (公共头部)" << endl;
    }

    void footer()
    {
        cout << "帮助中心、交流合作、站内地图 ... (公共底部)" << endl;
    }

    void left()
    {
        cout << "Java、Python、C++ ... (公共分类列表)" << endl;
    }
};

class Java: public BasePage
{
public:
    void content()
    {
        cout << "Java学科vido" << endl;
    }
};

class Python: public BasePage
{
public:
    void content()
    {
        cout << "Python学科vido" << endl;
    }
};

class Cpp: public BasePage
{
public:
    void content()
    {
        cout << "c++学科vido" << endl;
    }
};


void test01()
{
    Java j;
    cout << "======== Java =======" << endl;
    j.header();
    j.footer();
    j.left();
    j.content();

    Python p;
    cout << "======== Python =======" << endl;
    p.header();
    p.footer();
    p.left();
    p.content();

    Cpp c;
    cout << "======== Cpp =======" << endl;
    c.header();
    c.footer();
    c.left();
    c.content();

}

int main()
{
    test01();
    return 0;
}