// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem303.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    vector<int> sums;
    int size;

    NumArray(vector<int>& nums) {
        // nums_.assign(nums.begin(),nums.end());
        size = nums.size();
        sums.resize(size+1);
        sums[0]=0;
        for(int i=1;i<size+1;i++){
            sums[i]=sums[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j+1]-sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

