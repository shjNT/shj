#include <iostream>
using namespace std;
#include "my_func.hpp"

void solve_sum(int a, int b, int c)
{
    cout << a + b + c << endl;
    if(a>b)
    {
        cout << "a>b" << endl;
    }
    else{
        cout << "b>a" << endl;
    }
}
