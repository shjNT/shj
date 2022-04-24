#include <iostream>
using namespace std;
#include<map>
#include<unordered_map>
#include <algorithm>

// 外观数列

class Solution
{
public:
    string countAndSay(int n)
    {
        string prev = "1";
        for(int i = 2; i<=n; i++)
        {
            string cur = "";
            int start = 0;
            int pos = 0;

            while(pos < (int)prev.size())
            {
                while(pos<(int)prev.size() && prev[pos] == prev[start])
                {
                    pos ++;
                }
                cur += to_string(pos-start) + prev[start];
                start = pos;
            }
            prev = cur;
        }
        return prev;
    }
};

int main()
{
    Solution sol;
    string rslt = sol.countAndSay(4);
    cout << 11 << endl;
    cout << rslt << endl;
    return 0;
}