// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem81.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if(n==0){
            return false;
        }
        if(n==1){
            return nums[0]==target;
        }
        int k=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                k=i;
                break;
            }
        }
        int l;
        int left = k;
        int right = k + n - 1;
        while (left <= right)
        {
            l = (left + right) / 2;
            if (nums[l % n] == target)
            {
                return true;
            }
            else if (nums[l % n] < target)
            {
                left = l + 1;
            }
            else
            {
                right = l - 1;
            }
        }
        return false;
    }
};
// @lc code=end
