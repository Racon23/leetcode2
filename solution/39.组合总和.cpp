// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem39.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
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
            ret.emplace_back(cur);
            return;
        }
        else if (rest < 0)
        {
            return;
        }
        else
        {
            int n = candidates.size();
            for (int i = last; i < n; i++)
            {
                cur.emplace_back(candidates[i]);
                backtrace(candidates, ret, cur, rest - candidates[i], i);
                cur.pop_back();
            }
        }
    }
};
// @lc code=end
