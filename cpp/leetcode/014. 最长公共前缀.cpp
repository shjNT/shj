#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string rslt;
        int len1 = strs[0].size();
        for(int i=0; i<len1; i++)
        {
            for (int j=1; j<(int)strs.size(); j++)
            {
                if(strs[j][i] != strs[0][i])
                {
                    return rslt;
                }
            }
            rslt += strs[0][i];
        }

        // cout << rslt << endl;
        return rslt;    
    }
};

int main()
{
    Solution sol;
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");
    sol.longestCommonPrefix(strs);
    return 0;
}