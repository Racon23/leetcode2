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
// 入度出度
class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        int i = 0;
        int count = 1;
        int len = preorder.length();
        while (i < len && count > 0)
        {
            if (preorder[i] == '#')
            {
                count--;
                i+=2;
            }
            else
            {
                while (isdigit(preorder[i]))
                {
                    i++;
                }
                i++;
                count++;
            }
        }

        return count == 0&&i>=len;
    }
};
// @lc code=end
