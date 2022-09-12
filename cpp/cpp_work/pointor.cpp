//
// Created by Administrator on 2022/9/12.
//

/*一、
 1.指针：int a;  &a;  int *a;  *a;
 2.函数参数：void func(int *a, int *b){}  -->> func(&a, &b);
 3.const:   ①const int * a;  不能解引用修改
            ②int * const a;  不能修改指向的变量地址
            ③const int * const a;
 4.void:  void *:
 */

/* 二、
 动态分配内存：new和delete：
 步骤：
 ① 声明一个指针
 ② 用new向系统申请一块内存，让指针指向这块内存
 ③ 指针解引用，像使用变量使用这块内存
 ④ 不用了用delete释放
 */

/* 三、
二级指针：指向指针的指针
 int **a;
 */

/* 四、
 空指针：声明指针后，在赋值之前可以指向空，表明没有指向任何地址；用nullptr示
 不可访问解引用；   一般在函数指针传递时要判断空指针；

 野指针：指针指向不合法（无效）的地址
 出现情况：①无初始化；②指向的动态分配地址释放后；③超出变量作用域（函数返回局部变量地址等）
 */

/* 五、一维数组和指针
 1.数组本质：数组是占用一块连续空间的内存

 */

#include <iostream>
using namespace std;
#include <string>


// 1.函数地址传递
void func1(int a, int b, int c, int *max, int *min)
{
    *max = a > b ? a: b;
    *min = a < b ? a: b;
    *max = *max > c ? *max: c;
    *min = *min < c ? *min: c;
}

void demo1()
{
    int a = 187, b= 175, c=168, m, n;
    func1(a, b, c, &m, &n);
    cout << m << ", " << n << endl;
}


// 2. void *
void func1(string varname, void *p)
{
    cout << varname << "的地址是" << p << endl;
}

void demo2()
{
    string s = "sss";
    int t = 44;
    func1(s, &s);
    func1(s, &t);
}

// 3.new,delete
void demo3()
{
    int *p = new int(5);
    cout << *p  << endl;
    *p = 8;
    cout << *p << endl;
}

// 4. int **
void func2()
{
    int * a = new int(3);
    int **i = &a;
    cout << "i = " << i << "  *i = " << *i << "  a = " << a << "  **i = " << **i << "  *a = " << *a << endl;
}
void func3(int ** a)
{
    cout << "**a=" << **a << endl;
    *a = new int(44);
}
void demo4()
{
    int *p = new int(4);
    func3(&p);
    cout << "*p = " << *p << endl;
}

// 5.nullptr、野指针
void demo5()
{
    int * p1 = nullptr;
//    cout << *p1 << endl;

    int *p2 = new int(3);
    delete p2;
//    cout << "p2=" << p2 << ", *p2=" << *p2 << endl;
}

//6. 一维数组的指针
void demo6()
{
    int v[5] = {1, 2, 3, 4, 5};
    cout << "v的地址：" << (long long )v << endl;
    cout << "v的地址：" << (long long )&v << endl;
    cout << "v[0]的地址：" << (long long )&v[0] << endl;
    cout << "v[1]的地址：" << (long long )&v[1] << endl;
}

int main()
{
    demo1();
    demo2();
    demo3();
    func2();
    demo4();
    demo5();
    demo6();
    return 0;
}