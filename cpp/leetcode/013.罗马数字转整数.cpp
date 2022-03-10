#include <iostream>
using namespace std;

// 罗马数字转整数

class Solution
{
public:
    int romanToInt(string s)
    {
        int len = s.size();
        int rslt = 0;

        for (int i=0; i< len; i++)
        {
            if(s[i] == 'M')
            {
                rslt += 1000;
            }
            else if(s[i]=='C' && s[i+1] == 'M')
            {
                rslt += 900;
                i++;
            }
            else if(s[i]=='C' && s[i+1] == 'D')
            {
                rslt += 400;
                i++;
            }
            else if(s[i] == 'D')
            {
                rslt += 500;
            }
            else if(s[i] == 'C')
            {
                rslt += 100;
            }

            else if(s[i]=='X' && s[i+1] == 'C')
            {
                rslt += 90;
                i++;
            }
            else if(s[i]=='X' && s[i+1] == 'L')
            {
                rslt += 40;
                i++;
            }
            else if(s[i] == 'L')
            {
                rslt += 50;
            }
            else if(s[i] == 'X')
            {
                rslt += 10;
            }

            else if(s[i]=='I' && s[i+1] == 'X')
            {
                rslt += 9;
                i++;
            }
            else if(s[i]=='I' && s[i+1] == 'V')
            {
                rslt += 4;
                i++;
            }
            else if(s[i] == 'V')
            {
                rslt += 5;
            }
            else if(s[i] == 'I')
            {
                rslt += 1;
            }


            // cout << i << "  " << rslt << endl;
        }
        // if(i < len-1)
        // {
        //     rslt
        // }
        return rslt;
    }
};

int main()
{
    Solution sol;
    sol.romanToInt("MC");
    return 0;
}