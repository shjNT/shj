#include <iostream>
using namespace std;
#include <vector>
#include<map>

// 49. 字母异位词分组

class Solution
{
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string> > mp;
        for(string s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string> > ans;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};


int main()
{
    return 0;
}