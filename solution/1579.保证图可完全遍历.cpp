#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=1579 lang=cpp
 *
 * [1579] 保证图可完全遍历
 */

// @lc code=start
class Solution
{

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

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        int en = edges.size();

        vector<int> parent1(n + 1, 0);
        vector<int> rank1(n + 1, 0);

        vector<int> parent2(n + 1, 0);
        vector<int> rank2(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            parent1[i] = i;
            parent2[i] = i;
        }
        // sort(edges.begin(), edges.end(), [](auto &e1, auto &e2) {
        //     return e1[0] > e2[0];
        // });
        int ans = 0;
        for (auto &e : edges)
        {
            if (e[0] == 3)
            {

                int x_root = find1(e[1], parent1);
                int y_root = find1(e[2], parent1);
                if (x_root == y_root)
                {
                    ans++;
                }
                else
                {
                    union1(e[1], e[2], parent1, rank1);
                    union1(e[1], e[2], parent2, rank2);
                }
            }
        }
        for (auto &e : edges)
        {
            if (e[0] == 1)
            {
                int x_root = find1(e[1], parent1);
                int y_root = find1(e[2], parent1);
                if (x_root == y_root)
                {
                    ans++;
                }
                else
                {
                    union1(e[1], e[2], parent1, rank1);
                }
            }
            else if (e[0] == 2)
            {
                int x_root = find1(e[1], parent2);
                int y_root = find1(e[2], parent2);
                if (x_root == y_root)
                {
                    ans++;
                }
                else
                {
                    union1(e[1], e[2], parent2, rank2);
                }
            }
        }
        int s1 = 0, s2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == parent1[i])
            {
                s1++;
            }
            if (i == parent2[i])
            {
                s2++;
            }
            if (s1 > 1 || s2 > 1)
            {
                return -1;
            }
        }
        return ans;
    }
};
// @lc code=end
