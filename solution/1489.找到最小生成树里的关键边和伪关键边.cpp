#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
 * @lc app=leetcode.cn id=1489 lang=cpp
 *
 * [1489] 找到最小生成树里的关键边和伪关键边
 */

// @lc code=start
// 并查集 暴力枚举
class UnionFind
{

public:
    vector<int> parent; // 祖先
    vector<int> size;   // 该祖先下的点个数
    int setCount;       // 连通量
    int n;              //点个数

    UnionFind(int _n) : n(_n), setCount(_n), parent(_n), size(_n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int findset(int x)
    {
        return x == parent[x] ? x : parent[x] = findset(parent[x]);
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
            if (size[x] < size[y])
            {
                swap(x, y);
            }
            parent[y] = x;
            size[x] += size[y];
            --setCount;
            return true;
        }
    }

    bool connected(int x, int y)
    {
        return findset(x) == findset(y);
    }
};

class Solution
{
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        int m = edges.size();
        for (int i = 0; i < m; i++)
        {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](auto &u, auto &v) {
            return u[2] < v[2];
        });
        UnionFind uf_std(n);
        int value = 0;
        for (int i = 0; i < m; i++)
        {
            if (uf_std.unite(edges[i][0], edges[i][1]))
            {
                value += edges[i][2];
            }
        }

        vector<vector<int>> ans(2, vector<int>());
        for (int i = 0; i < m; i++)
        {
            // 判断是否关键边
            UnionFind uf(n);
            int v = 0;
            for (int j = 0; j < m; j++)
            {
                if (i != j && uf.unite(edges[j][0], edges[j][1]))
                {
                    v += edges[j][2];
                }
            }
            // 当连通量!=1 或者 权值比最小生成树大
            if (uf.setCount != 1 || (uf.setCount == 1 && v > value))
            {
                ans[0].push_back(edges[i][3]);
                continue;
            }

            // 判断是否伪关键边
            uf = UnionFind(n);
            uf.unite(edges[i][0], edges[i][1]);
            v = edges[i][2];
            for (int j = 0; j < m; j++)
            {
                if (i != j && uf.unite(edges[j][0], edges[j][1]))
                {
                    v += edges[j][2];
                }
            }
            if(v==value){
                ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};
// @lc code=end
