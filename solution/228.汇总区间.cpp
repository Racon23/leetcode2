// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem228.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        int n = nums.size();
        vector<string> ans;
        if(n==0) return ans;
        string last = to_string(nums[0]);
        int len = 1;
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1 || nums[i] + 1 != nums[i + 1])
            {
                if (len != 1)
                {
                    last.append("->");
                    last.append(to_string(nums[i]));
                }
                ans.emplace_back(last);
                if (i != n - 1)
                {
                    last = to_string(nums[i+1]);
                    len = 1;
                }
            }
            else
            {
                len++;
            }
        }
        return ans;
    }
};
// @lc code=end
