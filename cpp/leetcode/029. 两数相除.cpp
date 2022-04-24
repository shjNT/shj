#include <iostream>
using namespace std;
#include<math.h>

// 两数相除

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // 考虑被除数为最小值的情况
        if (dividend == INT_MIN) {
            if (divisor == 1) {
                return INT_MIN;
            }
            if (divisor == -1) {
                return INT_MAX;
            }
        }

        // 除数为最小值
        if(divisor == INT_MIN)
        {
            return dividend == INT_MIN ? 1: 0;
        }

        // 被除数为0
        if(dividend == 0) return 0;

        // // 二分查找
        // bool rev = false;
        // if(dividend > 0)
        // {
        //     dividend = -dividend;
        //     rev = !rev;
        // }

        // if(divisor > 0)
        // {
        //     divisor = -divisor;
        //     rev = !rev;
        // }


        return dividend / divisor;
    }
};

int main()
{
    Solution sol;
    int r = sol.divide(-2147483648, -1);
    cout << r << endl;
    cout << pow(2, 31) << endl;
    return 0;
}