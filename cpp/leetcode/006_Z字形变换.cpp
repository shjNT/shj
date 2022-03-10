#include <iostream>
using namespace std;
#include <vector>

// z字形变换

class Solution
{
public:
    string convert(string s, int numRows)
    {
        int len = s.size();
        if (len <= 2 || numRows == 1 || numRows >= len)
        {
            return s;
        }

        int col;
        if (len / (numRows * 2 - 2) == 0)
        {
            col = len - numRows + 1;
        }
        else
        {
            col = (len / (numRows * 2 - 2)) * (numRows - 1) + ((len % (numRows * 2 - 2)) > numRows ? (len % (numRows * 2 - 2))-numRows+1 : 1);
        }
        cout << col << endl;

        vector<string> v;
        for (int i = 0; i <= col-1; i++)
        {
            string sub_s(numRows, '0');
            v.push_back(sub_s);
        }

        for (int i = 0; i < len; i++)
        {
            int g_num = 2 * numRows - 2;
            int k = (i / g_num) * (numRows - 1) + (i % g_num - (numRows - 1) > 0 ? i % g_num - (numRows - 1) : 0);
            if(k >= col)
            {
                break;
            }
            // cout << k << endl;
            if (k % (numRows - 1) != 0)
            {
                int idx = (numRows - 1) - k % (numRows - 1);
                v[k][idx] = s[i];
            }
            else
            {
                int index = i % g_num;
                v[k][index] = s[i];
            }
        }

        for (int j = 0; j<col; j++)
        {
            cout << v[j] <<  endl;
        }

        string res;
        for (int i = 0; i <= numRows-1; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (v[j][i] != '0')
                {
                    res += v[j][i];
                }
            }
        }
        // cout << res << endl;
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "PAYPALISHIRING";

    string r = sol.convert(s, 6);
    cout << r << endl;
    return 0;
}