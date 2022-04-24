#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include<numeric>

// 组合总和 II

class Solution
{
public:

    void dfs(vector<int> &candidates, vector<int> &combine, vector<vector<int> > &ans, int index, int target)
    {

        if(target == 0)
        {
            ans.push_back(combine);
            return;
        }

        if(index == (int)candidates.size()) return;

        dfs(candidates, combine, ans, index+1, target);
        
        if(target-candidates[index] >= 0)
        {
            combine.push_back(candidates[index]);
            dfs(candidates, combine, ans, index+1, target-candidates[index]);
            combine.pop_back();
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int> > ans;
        vector<int> combine;
        dfs(candidates, combine, ans, 0, target);

        vector<vector<int> > res;
        for(vector<int> item: ans)
        {
            sort(item.begin(), item.end());
            vector<vector<int> >::iterator it = find(res.begin(), res.end(), item);
            if(it == res.end()) res.push_back(item);
        }
        return res;
    }
};

int main()
{
    vector<int> candidates = {10,1,2,7,6,1,5};
    Solution s;
    vector<vector<int> > rslt = s.combinationSum2(candidates, 8);
    
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