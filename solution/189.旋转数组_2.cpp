// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem189.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
// 数组翻转
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+ k);
        reverse(nums.begin()+k,nums.end());

    }
};
// @lc code=end
