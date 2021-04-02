// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1006.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */

// @lc code=start
class Solution
{
public:
    int clumsy(int N)
    {
        int sign = 1;
        int ans = 0;
        int i = N;
        while (i > 0)
        {
            int temp = i--;
            if (i > 0)
                temp *= i--;
            if (i > 0)
                temp /= i--;
            if (i > 0)
                temp += i--*sign;
            ans += temp * sign;
            sign = -1;
        }
        return ans;
    }
};
// @lc code=end
