#include <iostream>
using namespace std;
#include <vector>
#include <map>

// 串联所有单词的子串

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        map<string, int> search;
        for (auto &word : words)
            ++search[word]; //初始化hashmap

        // for (map<string, int>::iterator it = search.begin(); it != search.end(); it++)
        // {
        //     cout << "key=" << it->first << "\tvalue=" << it->second << endl;
        // }

        int n = s.size(), m = words.size(), len = words[0].size();

        for (int i = 0, j = 0; i < n - m * len + 1; ++i)
        {
            map<string, int> sub;
            for (j = 0; j < m; ++j)
            {
                auto word = s.substr(i + j * len, len);
                if (!search.count(word))
                    break;
                if (++sub[word] > search[word])
                    break;
            }

            if (j == m)
                res.push_back(i);
        }

        return res;
    }
};

int main()
{
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    Solution sol;
    vector<int> rslt = sol.findSubstring(s, words);
    cout << rslt[1] << endl;
    return 0;
}