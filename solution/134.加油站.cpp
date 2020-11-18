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
        if (n == 0)
            return -1;

        int flag = 0;

        for (int k = 0; k < n; k++)
        {
            flag = 0;
            if (gas[k] < cost[k])
            {
                continue;
            }

            int i = k;
            int sur = 0;
            while (i < n)
            {
                sur = gas[i] + sur - cost[i];
                i++;
                if (sur < 0)
                    flag = 1;
            }

            if (flag == 1)
                continue;

            i = 0;
            while (i < k)
            {
                sur = gas[i] + sur - cost[i];
                i++;
                if (sur < 0)
                    flag = 1;
            }
            if (flag == 1)
                continue;
            if(i==k) return k;
        }

        return -1;
    }
};
// @lc code=end
