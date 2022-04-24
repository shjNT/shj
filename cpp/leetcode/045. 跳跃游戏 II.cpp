#include <iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int start = 0;
        int end =1;
        while(end < (int)nums.size())
        {
            int max_pos = 0;
            for(int i = start; i< end; i++)
            {
                max_pos = max(max_pos, i+nums[i]);
            }
            start = end;
            end = max_pos+1;
            ans++;
        }
        return ans;
    }

};

int main()
{
    return 0;
}