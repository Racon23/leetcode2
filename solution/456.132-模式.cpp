// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem456.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
 */

// @lc code=start
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return false;
        int two = INT_MIN;
        stack<int> stk; //小顶堆，保存3
        for (int i = n - 1; i >= 0; i--)
        {
            if(nums[i]>=two){
                while(!stk.empty()&&nums[stk.top()]<nums[i]){
                    two = nums[stk.top()];
                    stk.pop();
                }
                stk.emplace(i);
            }else{
                // 3比2小，满足条件
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
