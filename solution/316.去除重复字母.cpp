// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem316.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        // vis 用于验证是否入栈
        vector<int> nums(26), vis(26);
        for (char &ch : s)
        {
            nums[ch - 'a']++;
        }
        string stk;
        for (char &ch : s)
        {
            if (!vis[ch - 'a'])
            {

                while (!stk.empty() && ch < stk.back() && nums[stk.back() - 'a'] > 0)
                {
                    // 入栈后会减1，所以nums是剩余字符的次数

                    vis[stk.back() - 'a'] = 0;
                    stk.pop_back();
                }
                vis[ch - 'a'] = 1;
                stk.push_back(ch);
            }
            nums[ch - 'a']--;
        }
        return stk;
    }
};
// @lc code=end
