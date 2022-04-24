#include <iostream>
using namespace std;
#include <vector>

// 搜索旋转排序数组

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int len = nums.size();
        for(int i=0; i<len; i++)
        {
            if (nums[i] == target) return i;
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {1};
    int target = 0;
    Solution sol;
    int rslt = sol.search(nums, target);
    cout << rslt << endl;
    return 0;
}