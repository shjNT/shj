#include<iostream>
using namespace std;

// 函数常见的4种样式: 无参无返；有参无返；无参有返；有参有返


// 无参无返
void test01(){
    cout << "无参无返" << endl;
}

// 有参无返
void test02(int a){
    cout << "有参无返, a=" << a << endl;
}

// 无参有返
string test03(){
    // cout << "无参有返"  << endl;
    return "无参有返";
}

// 有参有返
int test04(int a){
    cout << "有参有返"  << endl;
    return a;
}

int main(){

    test01();
    int a= 8;
    test02(a);
    string res=test03();
    cout << res << endl;

    int r = test04(1000);
    cout << r << endl;
    return 0;
}