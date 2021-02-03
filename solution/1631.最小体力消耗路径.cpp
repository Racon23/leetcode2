#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start
class Solution
{

public:
    vector<int> parent;
    vector<int> rank;

    int find1(int x)
    {
        if (x != parent[x])
        {
            parent[x] = find1(parent[x]);
        }
        return parent[x];
    }

    void union1(int x, int y)
    {
        int x_root = find1(x);
        int y_root = find1(y);
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

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<tuple<int, int, int>> edges;
        parent.resize(n * m, 0);
        rank.resize(n * m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int id = i * m + j;
                parent[id] = id;
                if (i > 0)
                {
                    edges.emplace_back(id, id - m, abs(heights[i][j] - heights[i - 1][j]));
                }
                if (j > 0)
                {
                    edges.emplace_back(id, id - 1, abs(heights[i][j] - heights[i][j - 1]));
                }
            }
        }

        sort(edges.begin(), edges.end(), [](const auto &e1, const auto &e2) {
            auto &&[x1, y1, v1] = e1;
            auto &&[x2, y2, v2] = e2;
            // 升序
            return v1 < v2;
        });

        int ans = 0;
        int esize = edges.size();
        for (int i = 0; i < esize; i++)
        {
            auto &&[x, y, v] = edges[i];
            union1(x, y);
            if (find1(n * m - 1) == find1(0))
            {
                ans = v;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
