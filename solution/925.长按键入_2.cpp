// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem925.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int i = 0, j = 0;
        int n = name.size();
        int m = typed.size();
        while (j < m)
        {
            if (i < n && name[i] == typed[j])
            {
                i++;
                j++;
            }
            else if (j > 0 && typed[j] == typed[j - 1])
            {
                j++;
            }
            else
            {
                return false;
            }
        }
        return i==n;
    }
};
// @lc code=end
