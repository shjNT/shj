#include <iostream>
using namespace std;

//字符串转换整数 (atoi)

class Solution
{
public:
    int myAtoi(string s)
    {
        long tmp=0;
        int k=0;
        while(k<(int)s.size() && s[k] == ' ') k++;

        int flag = 1;
        if(s[k] == '-')
        {
            flag = -1;
            k++;
        }
        else if(s[k] == '+') k++;

        if (s[k] > '9' || s[k] < '0') return 0;

        while(k < (int)s.size() && ('0' <= s[k] && s[k] <= '9'))
        {
            tmp = tmp * 10 + s[k]-'0';
            if (tmp-1>INT_MAX) break;

            k++;
        }
        tmp = flag * tmp;
        if (tmp>INT_MAX) return INT_MAX;
        if (tmp < INT_MIN) return INT_MIN;
        return tmp;
    }
};

int main()
{
    Solution sol;
    string s = "-91283472332";
    int r = sol.myAtoi(s);
    cout << r << endl;
    return 0;
}