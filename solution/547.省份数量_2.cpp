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
    int findParent(int idx1, vector<int> &parent)
    {
        if (parent[idx1] != idx1)
        {
            parent[idx1] = findParent(parent[idx1], parent);
        }
        return parent[idx1];
    }

    void unionCity(int idx1, int idx2, vector<int> &parent)
    {
        int i1 = findParent(idx1, parent);
        int i2 = findParent(idx2, parent);
        parent[i1] = i2;
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        if (n <= 1)
            return n;
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                    unionCity(i, j, parent);
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
