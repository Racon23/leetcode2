// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem605.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int len = flowerbed.size();
        if (n == 0)
            return true;
        for (int i = 0; i < len; i++)
        {
            if (flowerbed[i] == 1 || (i > 0 && flowerbed[i - 1] == 1) || (i < len - 1 && flowerbed[i + 1] == 1))
            {
                continue;
            }
            else
            {
                n--;
                if (n == 0)
                {
                    return true;
                }
                flowerbed[i] = 1;
                i++;
            }
        }
        return false;
    }
};
// @lc code=end
