// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <numeric>
#include "commoncppproblem803.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=803 lang=cpp
 *
 * [803] 打砖块
 */

// @lc code=start
class UnionFind
{
public:
    vector<int> parent;
    vector<int> size;
    int n;
    int setCount;

    UnionFind(int n_) : n(n_), setCount(n_), parent(vector<int>(n_)), size(vector<int>(n_, 1))
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int findset(int x)
    {
        return x == parent[x] ? x : findset(parent[x]);
    }

    bool unite(int x, int y)
    {
        x = findset(x);
        y = findset(y);
        if (x == y)
        {
            return false;
        }
        if ((x != (n - 1) && size[y] > size[x]) || y == n - 1)
        {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        setCount--;
        return true;
    }
};

class Solution
{
    int m;
    int n;
    bool inArea(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
    {
        int hs = hits.size();
        m = grid.size();
        n = grid[0].size();
        int size = m * n;
        vector<vector<int>> bk(m, vector<int>(n));
        // 防止打虚空靶
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bk[i][j] = grid[i][j];
            }
        }
        // 先全部打掉
        for (int i = 0; i < hs; i++)
        {
            bk[hits[i][0]][hits[i][1]] = 0;
        }
        UnionFind uf(size + 1);
        // size下标是屋顶，0行全部并到屋顶上
        for (int j = 0; j < n; j++)
        {
            if (bk[0][j] == 1)
            {
                uf.unite(size, j);
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (bk[i][j] == 1)
                {
                    if (bk[i - 1][j] == 1)
                    {
                        uf.unite(i * n + j, (i - 1) * n + j);
                    }
                    if (j > 0 && bk[i][j - 1] == 1)
                    {
                        uf.unite(i * n + j, i * n + j - 1);
                    }
                }
            }
        }
        vector<int> ans(hs, 0);
        int origin; // 旧的天花板砖个数
        // 逆序依次加入被打掉的砖块
        for (int k = hs - 1; k >= 0; k--)
        {
            int i = hits[k][0];
            int j = hits[k][1];
            // 虚空靶，如果此位置的砖块受上次射击影响已经掉落
            // 不会影响屋顶砖块数，只会与附近砖块抱团
            if (grid[i][j] == 0)
            {
                // 虚空靶
                continue;
            }
            origin = uf.size[size];
            if (i == 0)
            {
                uf.unite(size, j);
            }
            for (auto &d : dir)
            {
                int newx = i + d[0];
                int newy = j + d[1];
                if (inArea(newx, newy) && bk[newx][newy] == 1)
                {
                    uf.unite(i * n + j, newx * n + newy);
                }
            }

            bk[i][j] = 1;
            ans[k] = max(0, uf.size[size] - origin - 1);
        }
        return ans;
    }
};
// @lc code=end
