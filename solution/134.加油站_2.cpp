// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem134.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int i = 0;
        while (i < n)
        {
            int sog = 0, soc = 0;
            int cnt = 0;
            while (cnt < n)
            {
                int j = (i + cnt) % n;
                sog += gas[j];
                soc += cost[j];
                if (sog < soc)
                    break;
                cnt++;
            }
            if (cnt == n)
            {
                return i;
            }
            else
            {
                // 如果cnt!=n 说明上一个起点不满足条件
                // 由于sog一直比soc大，sog-soc[i]一定比sog-soc[i-1]大
                // 所以可以跳过从i到cnt的点
                i = i + cnt + 1;
            }
        }

        return -1;
    }
};
// @lc code=end
