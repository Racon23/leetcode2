// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include "commoncppproblem659.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 */

// @lc code=start
// 哈希表加最小堆
class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        int len = nums.size();
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> mp;
        for(int &x:nums){
            if(mp.find(x)==mp.end()){
                mp[x] = priority_queue<int,vector<int>,greater<int>>();
            }
            if(mp.find(x-1)!=mp.end()){
                int prevLen = mp[x-1].top();
                mp[x-1].pop();
                if(mp[x-1].empty()){
                    mp.erase(x-1);
                }
                mp[x].push(prevLen+1);
            }else{
                mp[x].push(1);
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            priority_queue<int,vector<int>,greater<int>> pq = it->second;
            if(pq.top()<3) return false;
        }
        return true;

    }
};W
// @lc code=end
