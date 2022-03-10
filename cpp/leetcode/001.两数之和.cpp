#include <iostream>
using namespace std;
#include <vector>
#include <map>

// 1. 两数之和

// 方法一：(暴力)
// 
// vector<int> twoSum(vector<int> &nums, int target)
// {
//     int n = nums.size();
//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = i + 1; j < n; ++j)
//         {
//             if (nums[i] + nums[j] == target)
//             {
//                 return {i, j};
//             }
//         }
//     }
//     return {};
// }

// 方法二：(哈希表)

vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> hash_table;
    for (int i =0; i<(int)nums.size(); i++)
    {
        auto it = hash_table.find(target-nums[i]);
        
        if(it != hash_table.end())
        {
            return {it->second, i};
        }

        hash_table[nums[i]] = i;
    }
    return {-1, -1};
}


int main()
{
    vector<int> v1;
    int a[4] = {2, 7, 11, 15};
    for (int i = 0; i < 4; i++)
    {
        v1.push_back(a[i]);
    }

    int target = 9;
    vector<int> v = twoSum(v1, target);

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it) << "  ";
    }
    cout << endl;
    return 0;
}