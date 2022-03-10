#include<iostream>
using namespace std;
#include<stack>


// stack容器


void test01()
{
    stack<int> s;
    for(int i=0; i< 5; i++)
    {
        s.push(i);
    }
    // cout << s.size() << endl;
    // s.pop(); 
    // cout << s.size() << endl;
    // cout << s.top() << endl;
    // cout << s.empty() << endl;

    cout << "栈的大小: " << s.size() << endl;
    while (!s.empty())
    {
        cout << "栈顶: " << s.top() << endl;
        s.pop();
    }
    cout << "栈的大小: " << s.size() << endl;
    

}

int main()
{
    test01();
    return 0;
}