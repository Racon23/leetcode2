// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem14.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (38.80%)
 * Likes:    1301
 * Dislikes: 0
 * Total Accepted:    375K
 * Total Submissions: 965.9K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        char c;
        int count = strs.size();
        if (count == 0)
        {
            return "";
        }
        int len = strs[0].size();
        if (len == 0)
        {
            return "";
        }
        for (int i = 0; i < len; i++)
        {
            c = strs[0][i];
            for (int j = 1; j < count; j++)
            {
                if (i == strs[j].size() || strs[j][i] != c)
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
// @lc code=end
