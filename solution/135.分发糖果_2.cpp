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
// 两次遍历
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int size = ratings.size();
        if (size <= 1)
            return size;
        int ans = 0;
        vector<int> cdy(size, 0);
        cdy[0] = 1;
        for (int i = 1; i < size; i++)
        {
            cdy[i] = ratings[i] > ratings[i - 1] ? cdy[i - 1] + 1 : 1;
        }
        for (int i = size - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                cdy[i] = max(cdy[i + 1] + 1, cdy[i]);
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
