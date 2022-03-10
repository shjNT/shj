#include<iostream>
using namespace std;

int main()
{
    string a = "1bcdefg";
    string b;
    b = a.substr(0, 4);
    cout << "b = " << b << endl;
    return 0;
}