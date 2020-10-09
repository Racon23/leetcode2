// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem12.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution
{
public:
    string intToRoman(int num)
    {
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string res;
        int i = 0;
        while (num > 0)
        {
            if (num - values[i] < 0)
            {
                i++;
            }
            else
            {
                num -= values[i];
                res = res + symbols[i];
            }
        }

        return res;
    }
};
// @lc code=end
