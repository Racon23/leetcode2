/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
//深度优先，遍历大陆
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return dfs(i, j, grid, m, n);
                }
            }
        }
        return 0;
    }

    int dfs(int i, int j, vector<vector<int>> &grid, int &m, int &n)
    {
        if (grid[i][j] == 2)
        {
            return 0;
        }
        grid[i][j] = 2;
        int border = 0;
        if (i == 0 || grid[i - 1][j] == 0)
        {
            border++;
        }
        else
        {
            border += dfs(i - 1, j, grid, m, n);
        }
        if (i == m - 1 || grid[i + 1][j] == 0)
        {
            border++;
        }
        else
        {
            border += dfs(i + 1, j, grid, m, n);
        }
        if (j == 0 || grid[i][j - 1] == 0)
        {
            border++;
        }
        else
        {
            border += dfs(i, j - 1, grid, m, n);
        }
        if (j == n-1 || grid[i][j + 1] == 0)
        {
            border++;
        }
        else
        {
            border += dfs(i, j + 1, grid, m, n);
        }
        return border;
    }
};
// @lc code=end
