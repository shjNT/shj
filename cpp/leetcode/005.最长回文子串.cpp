#include <iostream>
using namespace std;
#include <vector>

// 5.最长回文子串

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.size();
        if (len <= 1)
        {
            return s;
        }

        int start = 0;  // 记录结果起始位置
        int max = 1;    // 结果长度

        vector<vector<int> > dp(len, vector<int> (len));    // 动态规划数组

        // 初始化
        for(int i=0; i<len; i++)
        {
            dp[i][i] = 1;
            
            if (s[i] == s[i+1])
            {
                dp[i][i+1] = 1;
                max = 2;
                start = i;
            }
        }

        // 填充动态规划数组， max= 2的也已经填充完成，从长度为3开始
        for(int l = 3; l<=len; l++)
        {
            for(int i =0; i+l-1<len; i++)
            {
                int j = i + l -1;   // 终止字符位置
                if (s[i]== s[j] && dp[i+1][j-1] == 1)       // 状态转移
                {
                    dp[i][j] = 1;
                    max = l;
                    start = i;
                }
            }
        }

        return  s.substr(start, max);
    }
};

int main()
{
    Solution s;
    string st = "cbb";
    // cout << st << endl;
    string r = s.longestPalindrome(st);
    cout << r << endl;
    return 0;
}