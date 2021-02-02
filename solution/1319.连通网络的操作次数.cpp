#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=1319 lang=cpp
 *
 * [1319] 连通网络的操作次数
 */

// @lc code=start
class Solution
{
public:
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

    bool check1(int x, int y, vector<int> &parent)
    {
        int x_root = find1(x, parent);
        int y_root = find1(y, parent);
        if (x_root == y_root)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int en = connections.size();
        vector<int> parent(n, 0);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        int sp = 0;
        for (int i = 0; i < en; i++)
        {
            if (check1(connections[i][0], connections[i][1], parent))
            {
                sp++;
            }
            else
            {
                union1(connections[i][0], connections[i][1], parent, rank);
            }
        }
        int t = 0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                t++;
            }
        }
        int r = t-1;

        return sp >= r ? r : -1;
    }
};
// @lc code=end
