// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include "commoncppproblem1047.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicates(string S)
    {
        string stk;
        for(auto &ch:S){
            if(!stk.empty()&&ch==stk.back()){
                stk.pop_back();
            }else{
                stk.push_back(ch);
            }
        }
        return stk;
    }
};
// @lc code=end
