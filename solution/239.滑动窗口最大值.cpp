// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include "commoncppproblem239.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 默认less降序 大顶堆
        priority_queue<int,vector<int>> q;
        unordered_map<int,int> delay;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<k;i++){
            q.emplace(nums[i]);
        }
        ans.emplace_back(q.top());
        for(int i=k;i<n;i++){
            delay[nums[i-k]]++;
            while(delay.count(q.top())!=0) {
                delay[q.top()]--;
                if(delay[q.top()]==0){
                    delay.erase(q.top());
                }
                q.pop();
            }
            q.emplace(nums[i]);
            ans.emplace_back(q.top());
        }
        return ans;
    }
};
// @lc code=end

