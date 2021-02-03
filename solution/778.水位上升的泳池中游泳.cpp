// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <queue>
#include "commoncppproblem778.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=778 lang=cpp
 *
 * [778] 水位上升的泳池中游泳
 */

// @lc code=start
class Solution
{
public:
    int find1(int x, vector<int> &parent)
    {
        if (x != parent[x])
        {
            parent[x] = find1(parent[x], parent);
        }
        return parent[x];
    }

    void union1(int x, int y, vector<int> &parent, vector<int> &rank)
    {
        int x_root = find1(x, parent);
        int y_root = find1(y, parent);
        if (rank[x_root] > rank[y_root])
        {
            parent[y_root] = x_root;
        }
        else if (rank[x_root] < rank[y_root])
        {
            parent[x_root] = y_root;
        }
        else
        {
            parent[y_root] = x_root;
            rank[x_root]++;
        }
    }

    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> parent(n * n, 0);
        vector<int> rank(n * n, 0);
        for (int i = 0; i < n * n; i++)
        {
            parent[i] = i;
        }
        vector<vector<int>> mp(n * n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mp[grid[i][j]][0] = i;
                mp[grid[i][j]][1] = j;
            }
        }

        int t = 0;
        while (find1(grid[n - 1][n - 1], parent) != find1(grid[0][0],parent))
        {
            t++;
            int x = mp[t][0];
            int y = mp[t][1];
            if (x - 1 >= 0 && grid[x - 1][y] <= t)
            {
                union1(grid[x][y], grid[x - 1][y], parent, rank);
            }
            if (x + 1 < n && grid[x + 1][y] <= t)
            {
                union1(grid[x][y], grid[x + 1][y], parent, rank);
            }
            if (y - 1 >= 0 && grid[x][y - 1] <= t)
            {
                union1(grid[x][y], grid[x][y - 1], parent, rank);
            }
            if (y + 1 < n && grid[x][y + 1] <= t)
            {
                union1(grid[x][y], grid[x][y + 1], parent, rank);
            }
        }
        return t;
    }
};
// @lc code=end
