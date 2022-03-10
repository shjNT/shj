#include <iostream>
using namespace std;
#include "my_array.hpp"

// demo -->> 实现通用的数组类

void print_arr(MyArray<int> &arr)
{
    for (int i = 0; i < arr.get_size(); i++)
    {
        cout << arr[i] << endl;
    }
}

void test01()
{
    MyArray<int> arr1(5);
    // MyArray<int> arr2(arr1);
    // MyArray<int> arr3(100);
    // arr3 = arr1;
    for (int i = 0; i < 5; i++)
    {
        arr1.push_back(i);
    }
    cout << "arr1的打印输出为:" << endl;
    print_arr(arr1);
    cout << "arr1的容量大小:" << endl;
    cout << arr1.get_capacity() << "\t" << arr1.get_size() << endl;

    MyArray<int> arr2(arr1);
    cout << "arr2的打印输出为:" << endl;
    print_arr(arr2);

    arr2.pop_back();
    cout << "arr2的容量大小:" << endl;
    cout << arr2.get_capacity() << "\t" << arr2.get_size() << endl;
    cout << "arr2的打印输出为:" << endl;
    print_arr(arr2);
}

// 测试自定义数据类型
class Person
{
public:
    Person(){}
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;
};

void print_person_arr(MyArray<Person> &arr)
{
    for(int i=0; i<arr.get_size(); i++)
    {
        cout << "姓名: " << arr[i].m_name << "\t年龄: " << arr[i].m_age << endl;
    }
}

void test02()
{
    MyArray<Person> arr(10);

    Person p1("zhao", 999);
    Person p2("qian", 888);
    Person p3("sun", 777);
    Person p4("li", 666);
    Person p5("zhou", 555);
    Person p6("wu", 444);
    Person p7("zheng", 333);
    Person p8("wang", 222);

    // 将数据插入数组
    arr.push_back(p1);
    arr.push_back(p2);
    arr.push_back(p3);
    arr.push_back(p4);
    arr.push_back(p5);
    arr.push_back(p6);
    arr.push_back(p7);
    arr.push_back(p8);

    print_person_arr(arr);
    cout << arr.get_capacity() << "\t" << arr.get_size() << endl;
    
}

int main()
{
    // test01();
    test02();
    return 0;
}