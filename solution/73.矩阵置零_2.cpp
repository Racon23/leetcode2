// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem73.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int r1 = 1, c1 = 1;
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                c1 = 0;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                r1 = 0;
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                for (int i = 0; i < m; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (c1 == 0)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
        if (r1 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
    }
};
// @lc code=end
