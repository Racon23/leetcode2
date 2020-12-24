// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem135.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        queue<int> q;
        int size = ratings.size();
        int ans = 0;
        vector<int> cdy(size, 0);
        if (size <= 1)
            return size;
        for (int i = 0; i < size; i++)
        {
            if (i == 0 && ratings[i] <= ratings[i + 1] || i == size - 1 && ratings[i] <= ratings[i - 1] || i > 0 && i < size - 1 && ratings[i] <= ratings[i - 1] && ratings[i] <= ratings[i + 1])
            {
                q.emplace(i);
                cdy[i] = 1;
            }
        }
        while (!q.empty())
        {
            int idx = q.front();
            q.pop();
            if (idx > 0 && ratings[idx] < ratings[idx - 1])
            {
                cdy[idx - 1] = cdy[idx] + 1;
                q.emplace(idx-1);
            }
            if (idx < size - 1 && ratings[idx] < ratings[idx + 1])
            {
                cdy[idx + 1] = cdy[idx] + 1;
                q.emplace(idx+1);
            }
        }
        for (int i = 0; i < size; i++)
        {
            ans += cdy[i];
        }

        return ans;
    }
};
// @lc code=end
