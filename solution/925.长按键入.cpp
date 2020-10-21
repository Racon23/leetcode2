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
        if(n==0&&m==0){
            return true;
        }
        if (n == 0 || m == 0 || name[i] != typed[j])
        {
            return false;
        }
        else
        {
            i++;
            j++;
        }
        while (i < n && j < m)
        {
            if (name[i] == typed[j])
            {
                i++;
                j++;
            }
            else
            {
                if (typed[j] == typed[j - 1])
                {
                    j++;
                }
                else
                {
                    return false;
                }
            }
        }
        if(i<n){
            return false;
        }
        while (j < m)
        {
            if (typed[j] == typed[j - 1])
            {
                j++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
