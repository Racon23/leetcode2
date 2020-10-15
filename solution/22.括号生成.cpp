// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem22.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (76.40%)
 * Likes:    1366
 * Dislikes: 0
 * Total Accepted:    189K
 * Total Submissions: 247.4K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))",
 * ⁠      "(()())",
 * ⁠      "(())()",
 * ⁠      "()(())",
 * ⁠      "()()()"
 * ⁠    ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void generate(vector<string> &res,string &comb,int left,int right,int n){
        if(left==0&&right==0){
            res.emplace_back(comb);
        }
        if(left>0){
            comb.push_back('(');
            generate(res,comb,left-1,right,n);
            comb.pop_back();
        }
        if(right>left){
            comb.push_back(')');
            generate(res,comb,left,right-1,n);
            comb.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string comb;
        int left=n,right=n;
        generate(res,comb,left,right,n);
        return res;
    }
};
// @lc code=end

