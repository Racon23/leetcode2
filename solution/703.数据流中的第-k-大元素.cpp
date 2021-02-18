// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem703.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto &e:nums){
            add(e);
        }
    }
    
    int add(int val) {
        pq.emplace(val);
        if(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

