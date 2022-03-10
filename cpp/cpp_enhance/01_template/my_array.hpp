#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray
{
public:
    // 有参构造
    MyArray(int capacity)
    {
        // cout << "有参构造" << endl;
        this->m_capacity = capacity;
        this->m_size = 0;
        this->p_address = new T[this->m_capacity];
    }
    // 拷贝构造
    MyArray(const MyArray &arr)
    {
        // cout << "拷贝构造" << endl;
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        // this->p_address = arr.p_address;    // 浅拷贝：堆区数据重复释放

        this->p_address = new T[arr.m_capacity]; // 深拷贝

        // 拷贝arr中的数据
        for (int i = 0; i < this->m_size; i++)
        {
            this->p_address[i] = arr.p_address[i];
        }
    }

    // 重载operator=
    MyArray& operator=(const MyArray& arr)
    {
        // cout << "重载=" << endl;
        // 判断原来堆区是否有数据，若有先释放
        if (this->p_address != NULL)
        {
            delete this->p_address;
            p_address = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }

        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->p_address = new T[arr.m_capacity];

        for (int i = 0; i < this->m_size; i++)
        {
            this->p_address[i] = arr.p_address[i];
        }

        return *this;
    }

    // 尾插
    void push_back(const T &val)
    {
        if(this->m_capacity == this->m_size)
        {
            return;
        }
        this->p_address[this->m_size] = val;
        this->m_size++;
    }

    // 尾删
    void pop_back()
    {
        if (this->m_size == 0)
        {
            return;
        }

        this->m_size--; //用户访问不到最后一个元素，即为尾删
    }

    // 通过下标方式访问数组元素
    T & operator[](int index)
    {
        return this->p_address[index];
    }

    // 返回数组容量
    int get_capacity()
    {
        return this->m_capacity;
    }

    // 返回数组大小
    int get_size()
    {
        return this->m_size;
    }

    // 析构
    ~MyArray()
    {
        // cout << "析构函数" << endl;
        if (this->p_address != NULL)
        {
            delete this->p_address;
            this->p_address = NULL;
        }
    }

private:
    T * p_address;    // 指针指向堆区开辟的真是数组
    int m_capacity; //数组容量
    int m_size;     // 数组大小
};