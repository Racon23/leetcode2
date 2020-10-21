// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem26.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution
{
public:
    // vector<int> removeDuplicates(vector<int> &nums)
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int i=0;
        for(int j=1;j<n;j++){
            if(nums[j]>nums[i]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};
// @lc code=end
