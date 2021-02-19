// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include "commoncppproblem947.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=947 lang=cpp
 *
 * [947] 移除最多的同行或同列石头
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
        if (size[y] > size[x])
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
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        UnionFind uf(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (rows.count(stones[i][0]) == 1)
            {
                uf.unite(rows[stones[i][0]], i);
            }
            else
            {
                rows[stones[i][0]] = i;
            }
            if (cols.count(stones[i][1]) == 1)
            {
                uf.unite(cols[stones[i][1]], i);
            }
            else
            {
                cols[stones[i][1]] = i;
            }
        }
        return n - uf.setCount;
    }
};
// @lc code=end
