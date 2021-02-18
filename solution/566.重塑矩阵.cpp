// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem566.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int n = nums.size();
        int m = nums[0].size();
        if (n * m != r * c)
        {
            return nums;
        }
        vector<vector<int>> ans(r, vector<int>(c));

        int k = 0, l = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                ans[i][j] = nums[k][l];
                l++;
                if (l == m)
                {
                    l = 0;
                    k++;
                }
            }
        }

        return ans;
    }
};
// @lc code=end
