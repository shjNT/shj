#include <iostream>
using namespace std;
#include <vector>

// 括号生成 -->> 深度优先遍历

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        string cur_str;
        // cout << cur_str << endl;
        this->dfs(cur_str, n, n);
        return this->res;
    }

    // 深度优先遍历
    void dfs(string cur_str, int left, int right)
    // cur_str: 从根结点到叶子结点的路径字符串; left/right: 左右括号还可以使用的个数
    {
        // cout << cur_str << endl;
        if (left == 0 && right == 0)
        {
            this->res.push_back(cur_str);
            return;
        }
        if (right < left)
            return;
        if (left > 0)
        {
            dfs(cur_str + '(', left-1, right);
        }
        if (right > 0)
        {
            dfs(cur_str + ')', left, right-1);
        }
    }

    vector<string> res;
};

int main()
{
    Solution sol;
    vector<string> rslt = sol.generateParenthesis(3);
    cout << rslt.size() << endl;
    cout << rslt[0] << endl;
    cout << rslt[1] << endl;

    return 0;
}