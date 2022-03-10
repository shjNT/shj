#include<iostream>
using namespace std;
#include <queue>

// queue

void test01()
{
    queue<int> q;
    for (int i=0; i<5; i++)
    {
        q.push(i);
    }
    
    cout << "队列大小: " << q.size() << endl;
    while(!q.empty())
    {
        cout << "队首: " << q.front() << "\t队尾: " << q.back() << endl;
        q.pop();
    }
    cout << "队列大小: " << q.size() << endl;
}

int main()
{
    test01();
    return 0;
}