// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include "commoncppproblem85.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
// 单调栈
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

        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            stack<int> stk;
            vector<int> up(m, 0), down(m, m);

            for (int i = 0; i < m; i++)
            {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j])
                {
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }
            stk = stack<int>();

            for (int i = m - 1; i >= 0; i--)
            {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j])
                {
                    stk.pop();
                }
                down[i] = stk.empty() ? m : stk.top();
                stk.push(i);
            }

            for (int i = 0; i < m; i++)
            {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                ans = max(ans, area);
            }
        }

        return ans;
    }
};
// @lc code=end
