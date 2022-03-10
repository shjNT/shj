#include <iostream>
using namespace std;

// 整数转罗马数字

class Solution
{
public:
    string intToRoman(int num)
    {
        int tmp = num;
        int div = 1000;
        string res;
        while (div >= 10)
        {
            int tmp1, tmp2;
            tmp1 = tmp % div;
            tmp2 = tmp / div;

            string location;
            if (tmp2 != 0)
            {

                switch (div)
                {
                case 1000:
                {
                    if (0 < tmp2 && tmp2 < 4)
                    {
                        string location_t(tmp2, 'M');
                        location += location_t;
                    }
                }
                break;
                case 100:
                {
                    // cout << tmp1<< endl;
                    // cout << tmp2 << endl;
                    if (0 < tmp2 && tmp2 < 4)
                    {
                        string location_t(tmp2, 'C');
                        location += location_t;
                    }
                    else if (tmp2 == 4)
                    {
                        string location_t("CD");
                        location += location_t;
                    }
                    else if (4 < tmp2 && tmp2 < 9)
                    {
                        string location_t1("D");
                        string location_t2(tmp2 - 5, 'C');
                        location = location_t1 + location_t2;
                    }
                    else if (tmp2 == 9)
                    {
                        string location_t("CM");
                        location += location_t;
                    }
                    else
                        break;
                    // cout << location << endl;
                }
                break;

                case 10:
                {

                    if (0 < tmp2 && tmp2 < 4)
                    {
                        string location_t(tmp2, 'X');
                        location += location_t;
                    }
                    else if (tmp2 == 4)
                    {
                        string location_t("XL");
                        location += location_t;
                    }
                    else if (4 < tmp2 && tmp2 < 9)
                    {
                        string location_t1("L");
                        string location_t2(tmp2 - 5, 'X');
                        location = location_t1 + location_t2;
                    }
                    else if (tmp2 == 9)
                    {
                        string location_t("XC");
                        location += location_t;
                    }
                    else
                        break;
                }
                break;

                default:
                    break;
                }

            }
            res += location;
            location.clear();

            tmp = tmp1;
            div = div / 10;
   
        }

        // cout << tmp << endl;

        if (0 < tmp && tmp < 4)
        {
            string location_t(tmp, 'I');
            res += location_t;
        }
        else if (tmp == 4)
        {
            string location_t("IV");
            res += location_t;
        }
        else if (4 < tmp && tmp < 9)
        {
            string location_t1("V");
            string location_t2(tmp - 5, 'I');
            res += (location_t1 + location_t2);
        }
        else if (tmp == 9)
        {
            string location_t("IX");
            res += location_t;
        }
        
        return res;
    }
};

int main()
{
    Solution sol;
    string r = sol.intToRoman(40);
    cout << r << endl;
    return 0;
}