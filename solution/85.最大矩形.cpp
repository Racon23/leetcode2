// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem85.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        if (n == 0)
            return 0;
        vector<vector<int>> left(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            left[i][0] = matrix[i][0] - '0';
            for (int j = 1; j < n; j++)
            {
                left[i][j] = matrix[i][j] == '0' ? 0 : left[i][j - 1] + 1;
            }
        }

        int minwidth, area=0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                minwidth = left[i][j];
                area = max(area, minwidth);
                for (int k = i - 1; k >= 0 && left[k][j] > 0; k--)
                {
                    minwidth = min(minwidth, left[k][j]);
                    area = max(area, minwidth * (i - k + 1));
                }
            }
        }

        return area;
    }
};
// @lc code=end
