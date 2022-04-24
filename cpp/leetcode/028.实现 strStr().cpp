#include <iostream>
using namespace std;

// 实现 strStr()

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if(needle.empty()) return 0;
        int loc = haystack.find(needle);

        return loc;
    }
};

int main()
{
    string haystack("heloo");
    string needle("ll");
    Solution sol;
    sol.strStr(haystack, needle);
    return 0;
}