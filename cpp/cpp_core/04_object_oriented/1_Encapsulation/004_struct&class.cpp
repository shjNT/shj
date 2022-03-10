#include<iostream>
using namespace std;

// struct和class的区别
// struct和class的唯一区别在于默认的访问权限不同
// struct 默认公共； class 默认私有

class C1
{
    int id; //默认权限是私有
};

struct C2
{
    int id; // 默认权限是公共
};

int main(){
    C1 c1;
    // c1.id = 100; //私有权限不可访问
    
    C2 c2;
    c2.id = 100;

    return 0;
}