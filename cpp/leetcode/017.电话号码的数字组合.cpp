#include <iostream>
using namespace std;
#include <vector>
#include <map>

// 电话号码的字母组合

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        this->mp.insert(make_pair('2', "abc"));
        this->mp.insert(make_pair('3', "def"));
        this->mp.insert(make_pair('4', "ghi"));
        this->mp.insert(make_pair('5', "jkl"));
        this->mp.insert(make_pair('6', "mno"));
        this->mp.insert(make_pair('7', "pqrs"));
        this->mp.insert(make_pair('8', "tuv"));
        this->mp.insert(make_pair('9', "wxyz"));

        vector<string> combinations;
        if(digits.empty())
        {
            return combinations;
        }

        string combination;
        backtrack(combinations, mp, digits, 0, combination);
        return combinations;
    }

    void backtrack(vector<string> &combinations, const map<char, string> mp, const string digits,
                   int index, string &combination)
    {
        if(index == (int)digits.length())
        {
            combinations.push_back(combination);
        }
        else
        {
            char digit = digits[index];
            const string& letters = mp.at(digit);
            for(const char& letter: letters)
            {
                combination.push_back(letter);
                backtrack(combinations, mp, digits, index+1, combination);
                combination.pop_back();
            }

        }
    }

    map<char, string> mp;
};

int main()
{
    Solution sol;
    vector<string> r = sol.letterCombinations("23");
    for(int i=0; i<(int)r.size(); i++)
    {
        cout << r[i] << endl;
    }
    // cout << r << endl;
    return 0;
}