// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem26.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution
{
public:
    // vector<int> removeDuplicates(vector<int> &nums)
    int removeDuplicates(vector<int> &nums)
    {
        int i = 1, j, n = nums.size();
        // int temp;
        if (n == 0)
        {
            return 0;
            // return nums;
        }
        while (i < n && nums[i] > nums[i - 1])
        {
            i++;
        }
        j = i + 1;
        while (j < n)
        {
            // swap
            if (nums[j] > nums[i - 1])
            {
                // swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        // while(i<n){
        //     nums.pop_back();
        //     i++;
        // }
        // return nums;
        return i;
    }
};
// @lc code=end
