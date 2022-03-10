#include<iostream>
using namespace std;

// 计算器类案例
// 开发中的开闭原则：对扩展开放，对修改关闭

// 普通写法
class Cacultaor
{
public:

    int cal_result(string oper)
    {
        if(oper == "+")
        {
            return m_num1 + m_num2;
        }
        else if(oper == "-")
        {
            return m_num1 - m_num2;
        }
        else if(oper == "*")
        {
            return m_num2 * m_num1;
        }
        else{
            return 0;
        }
    }

    int m_num1;
    int m_num2;
};


// 多态写法

//基类 -> 抽象类
class AbstractCalculator
{
public:
    virtual int cal_result()
    {
        return 0;
    }
    int m_num1;
    int m_num2;
};

// 加法类
class AddCalculator: public AbstractCalculator
{
public:
    virtual int cal_result()
    {
        return m_num1 + m_num2;
    }
};

// 减法类
class SubCalculator: public AbstractCalculator
{
public:
    virtual int cal_result()
    {
        return m_num1 - m_num2;
    }
};

// 乘法类
class MulCalculator: public AbstractCalculator
{
public:
    virtual int cal_result()
    {
        return m_num1 * m_num2;
    }
};

// 除法类
class DivCalculator: public AbstractCalculator
{
public:
    virtual int cal_result()
    {
        return m_num1 / m_num2;
    }
};


void test01()
{
    Cacultaor c;
    c.m_num1 = 10;
    c.m_num2 = 10;
    cout << c.cal_result("+") << endl;
    cout << c.cal_result("-") << endl;
    cout << c.cal_result("*") << endl;
}

void test02()
{
    // 多态使用条件：父类的引用(指针)指向子类对象；
    AbstractCalculator * abc = new AddCalculator;
    abc->m_num1 = 105;
    abc->m_num2 = 10;
    cout << abc->cal_result() << endl;
    // 用完后释放
    delete abc;

    abc = new SubCalculator;  //释放的是堆区数据，指针类型没有变
    abc->m_num1 = 105;
    abc->m_num2 = 10;
    cout << abc->cal_result() << endl;
    // 用完后释放
    delete abc;

    abc = new MulCalculator;  //释放的是堆区数据，指针类型没有变
    abc->m_num1 = 10;
    abc->m_num2 = 10;
    cout << abc->cal_result() << endl;
    // 用完后释放
    delete abc;

    abc = new DivCalculator;  //释放的是堆区数据，指针类型没有变
    abc->m_num1 = 10;
    abc->m_num2 = 10;
    cout << abc->cal_result() << endl;
    // 用完后释放
    delete abc;
}

int main()
{
    // test01();
    test02();
    return 0;
}