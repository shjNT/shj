#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void dfs(vector<int> &candidates, int target, vector<vector<int> > &ans, vector<int> &combine, int idx)
    {
        if(idx == candidates.size()) return;
        if(target == 0)
        {
            ans.push_back(combine);
            return;
        }

        // 跳过当前数
        dfs(candidates, target, ans, combine, idx+1);
        
        // 选择当前数
        if(target - candidates[idx] >= 0)
        {
            combine.push_back(candidates[idx]);
            dfs(candidates, target-candidates[idx], ans, combine, idx);  //可以选择多次，idx不变
            combine.pop_back();
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int> > ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
    // void dfs(vector<int>& candidates, int target, vector<vector<int> >& ans, vector<int>& combine, int idx) {
    //     if (idx == candidates.size()) {
    //         return;
    //     }
    //     if (target == 0) {
    //         ans.emplace_back(combine);
    //         return;
    //     }
    //     // 直接跳过
    //     dfs(candidates, target, ans, combine, idx + 1);
    //     // 选择当前数
    //     if (target - candidates[idx] >= 0) {
    //         combine.emplace_back(candidates[idx]);
    //         dfs(candidates, target - candidates[idx], ans, combine, idx);
    //         combine.pop_back();
    //     }
    // }

    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     vector<vector<int>> ans;
    //     vector<int> combine;
    //     dfs(candidates, target, ans, combine, 0);
    //     return ans;
    // }

};

int main()
{
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int> > rslt = sol.combinationSum(candidates, 7);
    
    for(int i=0; i<(int)rslt.size(); i++)
    {
        for(int j =0; j<(int)rslt[i].size(); j++)
        {
            cout << rslt[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}