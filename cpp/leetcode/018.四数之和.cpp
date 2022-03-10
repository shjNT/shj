#include <iostream>
using namespace std;
#include <vector>

// 四数之和

class Solution
{
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int> > rslt;
        if (len < 4) return rslt;

        int a, b, c, d;

        for (a = 0; a < len - 3; a++)
        {
            if (a > 0 && nums[a] == nums[a - 1])
                continue;

            for (b = a + 1; b < len - 2; b++)
            {
                if (b > a + 1 && nums[b] == nums[b - 1])
                    continue;

                c = b + 1;
                d = len - 1;
                while (c < d)
                {
                    if (nums[a] + nums[b] - target < -(nums[c] + nums[d]))
                        c++;
                    else if (nums[a] + nums[b] - target > -(nums[c] + nums[d]))
                        d--;
                    else
                    {
                        rslt.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while (c < d && nums[c + 1] == nums[c])
                            c++;
                        while (c < d && nums[d - 1] == nums[d])
                            d--;

                        c++;
                        d--;
                    }
                }
                // cout << a <<"  "<<  b << "  "<< c << "  " << d << endl;
            }
        }
        return rslt;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int> > res = sol.fourSum(nums, target);
    for (int i = 0; i< (int)res.size(); i++)
    {
        for (int j=0; j< 4; j++)
        {
            cout << res[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}