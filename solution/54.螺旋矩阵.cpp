// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem54.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m1 = m;
        int n1 = n;
        int i = 0, j = 0;
        vector<int> ans;
        while (m1 > (m + 1) / 2 && n1 > (n + 1) / 2 && m > 1 && n > 1)
        {
            for (int d = 0; d < 4; d++)
            {
                while (!(d & 1) && j + dir[d][1] < n1 && j + dir[d][1] >= n - n1 || d & 1 && i + dir[d][0] < m1 && i + dir[d][0] >= m - m1)
                {
                    ans.emplace_back(matrix[i][j]);
                    i += dir[d][0];
                    j += dir[d][1];
                }
            }
            i++;
            j++;
            m1--;
            n1--;
        }
        if (m & 1 && m1 == (m + 1) / 2)
        {
            while (j < n1)
            {
                ans.emplace_back(matrix[i][j]);
                j++;
            }
        }
        else if (n & 1 && n1 == (n + 1) / 2)
        {
            while (i < m1)
            {
                ans.emplace_back(matrix[i][j]);
                i++;
            }
        }

        return ans;
    }
};
// @lc code=end
