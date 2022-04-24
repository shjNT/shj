#include<iostream>
using namespace std;


// 43. 字符串相乘

class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1 == "0" || num2 == "0") return "0";

        string ans = "0";
        int m = num1.size(), n = num2.size();
        
        for(int i=n-1; i>=0; i--)
        {
            string curr;
            int add = 0;
            for(int j = n-1; j>i; j--) curr.push_back(0);

            int y = num2.at(i) - '0';
            for (int j= m-1; j>=0; j--)
            {
                int x = num1.at(j) - '0';
                int product = x*y+add;
                curr.push_back(product % 10);
                add = product / 10;
            }
            while (add != 0)
            {
                curr.push_back(add % 10);
                add /= 10;
            }
            reverse(curr.begin(), curr.end());
            for(auto &c: curr) c+= '0';
            ans = addString(ans, curr);
        }
        return ans;
    }

    string addString(string num1, string num2)
    {
        int i = num1.size()-1, j =num2.size()-1, add=0;
        string ans;
        while (i>=0 || j>=0 || add !=0)     
        {
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            int res = x + y + add;
            ans.push_back(res % 10);
            add = res /10;
            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());
        for(auto &c : ans) c+= '0';
        return ans;
        
    }
};


int main()
{
    Solution sol;
    string rslt = sol.multiply("123456789", "987654321");
    cout << rslt << endl;
    return 0;
}