#include<iostream>
using namespace std;

// 回文数


class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        reverse(s.begin(), s.end());
        int x1 = atol(s.c_str());

        if(x == x1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


int main()
{
    Solution sol;
    bool r = sol.isPalindrome(1);
    cout << r << endl;
    return 0;
}