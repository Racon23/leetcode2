#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
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

    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.length();
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        int psize = pairs.size();
        for (int i = 0; i < psize; i++)
        {
            int x = pairs[i][0];
            int y = pairs[i][1];
            union1(x, y, parent, rank);
        }

        vector<char> cs(n);

        // 整合连通分量
        // 键是根，值是父节点是这个根的值的数组
        unordered_map<int, vector<int>> mp;
        // 记录根，方便遍历
        vector<int> rs;
        for (int i = 0; i < n; i++)
        {
            int x_root = find1(i, parent);
            if (mp.find(x_root) == mp.end())
            {
                mp.emplace(x_root, vector<int>());
                rs.emplace_back(x_root);
            }
            mp[x_root].emplace_back(i);
        }

        int rsize = rs.size();
        for (int i = 0; i < rsize; i++)
        {
            int root = rs[i];
            int rcsize = mp[root].size();
            vector<char> vc;
            for (int j = 0; j < rcsize; j++)
            {
                vc.emplace_back(s[mp[root][j]]);
            }
            sort(vc.begin(), vc.end());
            for (int j = 0; j < rcsize; j++)
            {
                cs[mp[root][j]] = vc[j];
            }
        }

        string ans;
        ans.assign(cs.begin(), cs.end());
        return ans;
    }
};
// @lc code=end
