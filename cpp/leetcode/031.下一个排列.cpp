#include <iostream>
using namespace std;
#include <vector>

// 下一个排列

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int len = nums.size();

        bool flag = true;

        for(int i =len-1; i>0; i--)
        {
            if(nums[i] > nums[i-1])
            {
                // if(i-1 == 0)
                // {
                //     int j = len-1;
                //     while(nums[j] <= nums[i-1]) --j;
                //     swap(nums[i-1], nums[j]);
                //     sort(nums.begin()+i, nums.end());
                //     flag = false;
                //     break;
                // }
                int j = len-1;
                while(nums[j] <= nums[i-1]) --j;
                swap(nums[i-1], nums[j]);
                sort(nums.begin()+i, nums.end());
                flag = false;
                break;
            }
        }

        if(flag) sort(nums.begin(), nums.end());
    }
};

int main()
{
    vector<int> nums = {2,2,7,5,4,3,2,2,1};
    // cout << nums.back() << endl;
    Solution sol;
    sol.nextPermutation(nums);

    int i = 0;
    while(i<nums.size())
    {
        cout << nums[i] << "  ";
        i++;
    }
    cout << endl;
    return 0;
}