// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem561.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */

// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i+=2){
            ans+=nums[i];
        }
        return ans;
    }
};
// @lc code=end

