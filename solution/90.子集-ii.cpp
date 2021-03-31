// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem90.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {

private:
    vector<vector<int>> ans;
    vector<int> temp;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        ans.push_back(temp);
        backtrace(nums,n,0);
        return ans;
    }

    void backtrace(vector<int> &nums, int n,int i){
        for(int j=i;j<n;j++){
            if(j>i&&nums[j]==nums[j-1]){
                continue;
            }
            temp.emplace_back(nums[j]);
            ans.push_back(temp);
            backtrace(nums,n,j+1);
            temp.pop_back();
        }
    }
};
// @lc code=end

