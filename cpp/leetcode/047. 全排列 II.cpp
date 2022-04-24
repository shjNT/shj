#include <iostream>
using namespace std;
#include <vector>

// 47. 全排列 II

class Solution
{
public:
    void backtrack(vector<int> &nums, vector<vector<int> > &ans, int idx, vector<int> &prem)
    {
        if(idx == nums.size())
        {
            ans.push_back(prem);
            return;
        }

        for(int i=0; i<(int)nums.size(); i++)
        {
            if(vis[i] || (i>0 && nums[i] == nums[i-1] && !vis[i-1])) continue;

            prem.push_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, ans, idx+1, prem);
            vis[i] = 0;
            prem.pop_back();
        }
    }


    vector<vector<int> > permuteUnique(vector<int> &nums)
    {
        vector<vector<int> > ans;
        vector<int> prem;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, ans, 0, prem);
        return ans;
    }

private:
    vector<int> vis;
};

int main()
{
    return 0;
}