// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem781.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */

// @lc code=start
class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        vector<int> rem(1001, 0);
        int ans = 0;
        int n = answers.size();
        for (int i = 0; i < n; i++)
        {
            rem[answers[i] + 1]++;
        }
        for (int i = 1; i < 1001; i++)
        {
            // ans += ceil(rem[i] * 1.0 / i) * i;
            ans += (rem[i] + i - 1) / i * i;
        }
        return ans;
    }
};
// @lc code=end
