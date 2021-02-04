// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem959.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=959 lang=cpp
 *
 * [959] 由斜杠划分区域
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
            rank[x_root]++;
            parent[y_root] = x_root;
        }
    }

    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        int an = n * n * 4;
        vector<int> parent(an, 0);
        vector<int> rank(an, 0);
        for (int i = 0; i < an; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int len = grid[i].length();
            // int count= 0;//记录反斜杠次数
            for (int j = 0; j < len; j++)
            {
                int id = (i * n + j) * 4;
                if (grid[i][j] == ' ')
                {
                    union1(id, id + 1, parent, rank);
                    union1(id, id + 2, parent, rank);
                    union1(id, id + 3, parent, rank);
                    // 左边
                    if (j > 0)
                    {
                        union1(id, id - 3, parent, rank);
                    }
                    // 上边
                    if (i > 0)
                    {
                        union1(id, id - n * 4 + 2, parent, rank);
                    }
                }
                else if (grid[i][j] == '/')
                {
                    union1(id, id + 3, parent, rank);
                    union1(id + 1, id + 2, parent, rank);
                    if (j > 0)
                    {
                        union1(id, id - 3, parent, rank);
                    }
                    if (i > 0)
                    {
                        union1(id, id - n * 4 + 2, parent, rank);
                    }
                }
                else
                {
                    union1(id, id + 1, parent, rank);
                    union1(id + 2, id + 3, parent, rank);
                    if (j > 0)
                    {
                        union1(id + 3, id - 3, parent, rank);
                    }
                    if (i > 0)
                    {
                        union1(id, id - n * 4 + 2, parent, rank);
                    }
                    // count++;
                    // j++;
                }
            }
        }
        int ans=0;
        for (int i=0;i<an;i++){
            if(i==find1(i,parent)){
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
