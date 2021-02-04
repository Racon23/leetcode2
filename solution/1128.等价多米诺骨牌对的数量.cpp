#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        vector<int> nums(100, 0);
        int ret = 0;
        for (auto &e : dominoes)
        {
            int t = e[0] > e[1] ? e[1] * 10 + e[0] : e[0] * 10 + e[1];
            ret += nums[t];
            nums[t]++;
        }
        return ret;
    }
};
// @lc code=end
