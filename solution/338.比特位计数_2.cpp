// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem338.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
// 动态规划
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1, 0);
        for (int i = 1; i <= num; i++)
        {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};
// @lc code=end
