// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem27.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int i = 0, j = n - 1;
        if (n == 0 )
        {
            return 0;
        }
        while (i < j)
        {
            if (val == nums[i])
            {
                nums[i] = nums[j];
                j--;
            }
            else
            {
                i++;
            }
        }
        if (nums[i] == val)
        {
            return i;
        }
        else
        {
            return i + 1;
        }
    }
};
// @lc code=end
