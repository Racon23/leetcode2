// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem514.h"

using namespace std;
// @before-stub-for-debug-end

#include <unordered_map>

/*
 * @lc app=leetcode.cn id=514 lang=cpp
 *
 * [514] 自由之路
 */

// @lc code=start
class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        int n = ring.size();
        int m = key.size();
        int ret = 0;
        unordered_map<char, vector<int>> ringmap;
        int mindist = 0;
        // 制作字典
        for (int i = 0; i < n; i++)
        {
            ringmap[ring[i]].push_back(i);
        }
        int prev = 0;
        int prev2 = 0;
        int min2 = 0;
        for (int i = 0; i < m; i++)
        {
            mindist = INT_MAX;
            // ringmap[ring[i]].push_back(i);
            vector<int> vec = ringmap[key[i]];
            for (int j = 0; j < vec.size(); j++)
            {
                if (vec[j] < prev)
                {
                    mindist = min(mindist, min(prev - vec[j], n + vec[j] - prev));
                }
                else if (vec[j] > prev)
                {
                    mindist = min(mindist, min(vec[j] - prev, n + prev - vec[j]));
                }
                else
                {
                    mindist = 0;
                }
            }
            
            ret++;
        }
        return ret;
    }
};
// @lc code=end
