// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem338.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution
{
public:
    int countOne(int x)
    {
        int count = 0;
        while (x != 0)
        {
            x &= (x - 1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1);
        for (int i = 0; i <= num; i++)
        {
            ans[i] = countOne(i);
        }
        return ans;
    }
};
// @lc code=end
