// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem697.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxn = 0, maxc = 0;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            if (mp.count(nums[i]) == 0)
            {
                mp[nums[i]].resize(3);
                mp[nums[i]][0] = 1;
                mp[nums[i]][1] = i;
                mp[nums[i]][2] = i;
            }
            mp[nums[i]][0]++;
            mp[nums[i]][2]=i;
        }
        for (auto &[k, vc] : mp)
        {

            if (maxc < vc[0] || (maxc == vc[0] && maxn > vc[2] - vc[1] + 1))
            {
                maxc = vc[0];
                maxn = vc[2] - vc[1] + 1;
            }
        }
        return maxn;
    }
};
// @lc code=end
