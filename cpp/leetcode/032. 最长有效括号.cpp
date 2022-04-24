#include <iostream>
using namespace std;
#include<stack>
#include<vector>
#include<algorithm>

// 最长有效括号

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int maxans = 0;
        stack<int> stk;
        stk.push(-1);
        for(int i=0; i<(int)s.length(); i++)
        {
            if(s[i] == '(') stk.push(i);
            else
            {
                stk.pop();
                if(stk.empty()) stk.push(i);
                else maxans = max(maxans, i-stk.top());
            }
        }

        return maxans;
    }
};

int main()
{
    string s = "(()(((()";
    Solution sol;
    int rslt = sol.longestValidParentheses(s);
    cout << rslt << endl;
    return 0;
}