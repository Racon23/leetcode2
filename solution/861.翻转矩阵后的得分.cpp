// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem861.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 */

// @lc code=start
class Solution
{
public:
    int matrixScore(vector<vector<int>> &A)
    {
        int m = A.size();
        int n = A[0].size();
        int ret = m * (1 << (n - 1)); // 第一列总和
        int sum = 0;
        for (int j = 1; j < n; j++)
        {
            sum = 0;
            for (int i = 0; i < m; i++)
            {
                if (A[i][0] == 1)
                {
                    sum += A[i][j];
                }
                else
                {
                    sum += 1 - A[i][j];
                }
            }
            int k = max(sum, m - sum);
            ret += k * (1 << (n - j - 1));
        }
        return ret;
    }
};
// @lc code=end
