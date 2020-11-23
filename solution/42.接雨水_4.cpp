// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include "commoncppproblem42.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
// 栈
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n <= 2)
            return 0;
        int ans = 0;
        stack<int> s;
        int cur = 0;
        int bh = 0;
        int dis = 0;
        int top = 0;
        while (cur < n)
        {
            while (!s.empty() && height[s.top()] < height[cur])
            {
                top = s.top();
                s.pop();
                // 当栈空时，没有stop，跳出
                if(s.empty()) break;
                dis = cur - s.top() - 1;
                bh = min(height[s.top()], height[cur]) - height[top];
                ans += dis * bh;
            }
            s.emplace(cur++);
        }

        return ans;
    }
};
// @lc code=end
