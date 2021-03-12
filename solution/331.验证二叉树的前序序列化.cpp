// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem331.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution
{
    int i;
    int len;
public:
    bool dfs(string &preorder)
    {
        if (i >= len)
        {
            return false;
        }
        if (preorder[i] == '#')
        {
            i += 2;
            return true;
        }
        while (isdigit(preorder[i]))
        {
            i++;
        }
        i++;
        return dfs(preorder) && dfs(preorder);
    }

    bool isValidSerialization(string preorder)
    {
        i=0;
        len = preorder.length();
        return dfs(preorder)&&i>=len;
    }
};
// @lc code=end
