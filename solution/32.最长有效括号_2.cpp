// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem32.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (34.03%)
 * Likes:    1053
 * Dislikes: 0
 * Total Accepted:    110.1K
 * Total Submissions: 323.5K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */

// @lc code=start
// 栈
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        stack<int> stk;
        int maxans = 0;
        stk.emplace(-1);
        for(int i = 0;i<n;i++){
            if(s[i]=='('){
                stk.emplace(i);
            }else{
                stk.pop();
                if(stk.empty()){
                    stk.emplace(i);
                }
                else{
                    maxans = max(maxans,i-stk.top());
                }
            }
        }
        
        return maxans;
    }
};
// @lc code=end
