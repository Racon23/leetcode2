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
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        if (n <= 1)
            return n;
        vector<int> cities(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (cities[i] == 0)
            {
                count++;
                queue<int> q;
                q.emplace(i);
                cities[i]=1;
                while (!q.empty())
                {
                    int cur = q.front();
                    q.pop();
                    for (int j = 0; j < n; j++)
                    {
                        if (isConnected[cur][j] == 1 && cities[j] == 0)
                        {
                            q.emplace(j);
                            cities[j] = 1;
                        }
                    }
                }
            }
        }
        return count;
    }
};
// @lc code=end
