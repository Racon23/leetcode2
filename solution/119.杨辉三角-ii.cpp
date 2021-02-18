// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem119.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex + 1, 1);
        if (rowIndex < 2)
            return ans;
        for (int i = 2; i <= rowIndex; i++)
        {
            int mid = i / 2;
            for (int j = mid; j >= 1; j--)
            {
                ans[j] = ans[j] + ans[j - 1];
            }
            if (i % 2 == 1)
            {
                ans[mid + 1] = ans[mid];
            }
        }
        int j = rowIndex % 2 == 0 ? rowIndex / 2 - 1 : rowIndex / 2;
        for (int i = rowIndex / 2 + 1; i < rowIndex; i++)
        {
            ans[i] = ans[j];
            j--;
        }
        return ans;
    }
};
// @lc code=end
