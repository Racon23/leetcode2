#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=1489 lang=cpp
 *
 * [1489] 找到最小生成树里的关键边和伪关键边
 */

// @lc code=start
// 并查集 tarjan找桥边
class UnionFind
{
public:
    vector<int> parent; // 祖先
    vector<int> rank;   // 权值
    int setCount;       //连通量
    int n;              // 点个数

    UnionFind(int n_) : n(n_), setCount(n_), parent(n_), rank(n_, 1)
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

class TarjanSCC
{
private:
    vector<vector<int>> edges;   // 点拥有的边连接的点
    vector<vector<int>> edgesId; // 点拥有的边id
    vector<int> low;             // 回溯时间戳
    vector<int> dfn;             // 遍历时间戳
    vector<int> ans;             // 桥边
    int n;                       // 点个数
    int ts;                      // 时间戳

    void getCuttingEdges_(int u, int parentEdge)
    {
        low[u] = dfn[u] = ++ts;
        int size = edges[u].size();
        for (int i = 0; i < size; i++)
        {
            int v = edges[u][i];
            int id = edgesId[u][i];
            if (dfn[v] == -1)
            {
                getCuttingEdges_(v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u])
                {
                    ans.emplace_back(id);
                }
            }
            else if (id != parentEdge)
            {
                // 遍历过的点，更新low[u] = dfn[v]
                // 为什么不是low[u]=low[v]，因为low[v]还受比它排序前的边影响
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

public:
    TarjanSCC(int n_, vector<vector<int>> &edges_, vector<vector<int>> &edgesId_)
        : n(n_), ts(-1), low(n_, -1), dfn(n_, -1), edges(edges_), edgesId(edgesId_)
    {
    }

    vector<int> getCuttingEdges()
    {
        for (int i = 0; i < n; i++)
        {
            if (dfn[i] == -1)
            {
                getCuttingEdges_(i, -1);
            }
        }
        return ans;
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
            edges[i].emplace_back(i);
        }
        sort(edges.begin(), edges.end(), [](auto &u, auto &v) {
            return u[2] < v[2];
        });

        UnionFind uf(n);
        vector<int> label(m, 0); // 标记边类型，-1 自环边 0 非关键边 1 关键边
        vector<vector<int>> ans(2);

        for (int i = 0; i < m;)
        {
            int w = edges[i][2];
            // 找到权重为w的边 [i,j)
            int j = i;
            while (j < m && edges[j][2] == w)
            {
                j++;
            }

            unordered_map<int, int> setId; // 记录点所在的连通id
            int gn = 0;                    // 图g的连通个数

            for (int k = i; k < j; k++)
            {
                int x = uf.findset(edges[k][0]);
                int y = uf.findset(edges[k][1]);
                if (x != y)
                {
                    if (!setId.count(x))
                    {
                        setId[x] = gn++;
                    }
                    if (!setId.count(y))
                    {
                        setId[y] = gn++;
                    }
                }
                else
                {
                    // 祖先相同，说明为自环边
                    label[edges[k][3]] = -1;
                }
            }

            vector<vector<int>> gm(gn), gmid(gn);
            for (int k = i; k < j; k++)
            {
                int x = uf.findset(edges[k][0]);
                int y = uf.findset(edges[k][1]);
                if (x != y)
                {
                    int idx = setId[x], idy = setId[y];
                    gm[idx].emplace_back(idy);
                    gm[idy].emplace_back(idx);
                    gmid[idx].emplace_back(edges[k][3]);
                    gmid[idy].emplace_back(edges[k][3]);
                }
            }

            // 找到的桥边即关键边
            vector<int> bridges = TarjanSCC(gn, gm, gmid).getCuttingEdges();
            int bsize = bridges.size();
            for (int k = 0; k < bsize; k++)
            {
                label[bridges[k]] = 1;
                ans[0].emplace_back(bridges[k]);
            }

            for (int k = i; k < j; k++)
            {
                uf.unite(edges[k][0], edges[k][1]);
            }

            i = j;
        }

        // 剩余未标记的边为非桥边，即伪关键边
        for (int i = 0; i < m; i++)
        {
            if (!label[i])
            {
                ans[1].emplace_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end
