// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include "commoncppproblem1046.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        int size = stones.size();
        for (int s : stones)
        {
            pq.emplace(s);
        }
        int st1 = 0, st2 = 0, nst = 0;
        while (pq.size() > 1)
        {
            st1 = pq.top();
            pq.pop();
            st2 = pq.top();
            pq.pop();
            nst = st1 - st2;
            if (nst > 0)
                pq.emplace(nst);
        }
        return pq.empty() ? 0 : pq.top();
    }
};
// @lc code=end
