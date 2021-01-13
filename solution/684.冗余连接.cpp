// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem684.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution
{
public:
    int find1(int x, vector<int> &parent)
    {
        if (parent[x] != x)
        {
            parent[x] = find1(parent[x], parent);
        }
        return parent[x];
    }

    bool union1(int x, int y, vector<int> &parent, vector<int> &rank)
    {
        int x_root = find1(x, parent);
        int y_root = find1(y, parent);
        if(x_root==y_root){
            return false;
        }
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
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        // 根据题意 最多n个点
        vector<int> parent(n + 1, -1);
        vector<int> rank(n + 1, 0);

        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }

        for (auto &edge : edges)
        {
            bool canUnion = union1(edge[0], edge[1], parent, rank);
            if (!canUnion)
            {
                return edge;
            }
        }
        return vector<int>{};
    }
};
// @lc code=end
