// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem547.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
// 并查集
class Solution
{
public:
    int findParent(int x, vector<int> &parent)
    {
        if (parent[x] != x)
        {
            // 只是在递归搜索过程中，顺便修改parent数组而已
            // 如果使用while循环，则不能顺便修改parent
            parent[x] = findParent(parent[x], parent);
        }
        return parent[x];
    }

    void unionSet(int x, int y, vector<int> &parent, vector<int> &rank)
    {
        int x_root = findParent(x, parent);
        int y_root = findParent(y, parent);
        if (rank[x] > rank[y])
        {
            parent[y_root] = x_root;
        }
        else if (rank[y] > rank[x])
        {
            parent[x_root] = y_root;
        }
        else
        {
            parent[y_root] = x_root;
            rank[x]++;
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        if (n <= 1)
            return n;
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                    unionSet(i, j, parent, rank);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
            {
                count++;
            }
        }

        return count;
    }
};
// @lc code=end
