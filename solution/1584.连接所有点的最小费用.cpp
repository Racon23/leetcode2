#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start
class UnionFind
{
public:
    vector<int> parent;
    vector<int> rank;
    int n;
    int setCount;

    UnionFind(int n_) : n(n_), setCount(n_), parent(n_), rank(n_, 1)
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
        else
        {
            if (rank[x] < rank[y])
            {
                swap(x, y);
            }
            parent[y] = x;
            rank[x] += rank[y];
            setCount--;
            return true;
        }
    }

    bool connected(int x, int y)
    {
        return findset(x) == findset(y);
    }
};

struct Edge
{
    int len, x, y;
    Edge(int len, int x, int y) : len(len), x(x), y(y)
    {
    }
};

class Solution
{

public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        auto dist = [&](int x, int y) {
            return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
        };
        UnionFind uf(n);
        vector<Edge> edges;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                edges.emplace_back(Edge(dist(i, j), i, j));
            }
        }
        int m = edges.size();
        sort(edges.begin(), edges.end(), [](auto &u, auto &v) {
            return u.len < v.len;
        });
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            if (uf.unite(edges[i].x, edges[i].y))
            {
                ans+=edges[i].len;
            }
        }
        return ans;
    }
};
// @lc code=end
