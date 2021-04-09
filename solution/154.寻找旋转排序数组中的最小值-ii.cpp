// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem154.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        while(left<right){
            int pivot = (left+right)/2;
            if(nums[pivot]<nums[right]){
                right = pivot;
            }else if(nums[pivot]>nums[right]){
                left = pivot+1;
            }else{
                right--;
            }
        }
        return nums[left];
    }
};
// @lc code=end

