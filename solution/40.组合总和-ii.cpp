// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem40.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
// 回溯
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ret;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, ret, cur, target, 0);
        return ret;
    }

    void backtrace(vector<int> &candidates, vector<vector<int>> &ret, vector<int> &cur, int rest, int last)
    {
        if (rest == 0)
        {
            ret.push_back(cur);
            return;
        }
        else if (rest < 0)
        {
            return;
        }
        else
        {
            int n = candidates.size();
            int l1 = -1;
            for (int i = last; i < n; i++)
            {
                if (candidates[i] == l1)
                    continue;
                l1 = candidates[i];
                cur.emplace_back(candidates[i]);
                backtrace(candidates, ret, cur, rest - candidates[i], i + 1);
                cur.pop_back();
            }
        }
    }
};
// @lc code=end
