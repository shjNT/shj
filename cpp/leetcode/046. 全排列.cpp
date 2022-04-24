#include <iostream>
using namespace std;
#include <vector>

// 46. 全排列

class Solution
{
public:
    vector<vector<int> > permute(vector<int> &nums)
    {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }

    void backtrack(vector<vector<int> > &res, vector<int> &output, int first, int len)
    {
        if(first == len)
        {
            res.push_back(output);
            return;
        }
        for(int i = first; i<len; i++)
        {
            swap(output[i], output[first]);
            backtrack(res, output, first+1, len);
            swap(output[i], output[first]);
        }
    }
};

int main()
{
    Solution sol;
    
    // cout << rslt << endl;
    return 0;
}