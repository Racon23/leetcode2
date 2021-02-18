// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem448.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int j = nums[i]<0?-nums[i]-1:nums[i]-1;
            nums[j]=nums[j]<0?nums[j]:-nums[j];
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]>0) {
                ans.emplace_back(i+1);
            }
        }
        return ans;
    }
};
// @lc code=end

