// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include "commoncppproblem264.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> factors={2,3,5};
        unordered_set<long> seen;
        priority_queue<long,vector<long>,greater<long>> heap;
        seen.emplace(1L);
        heap.emplace(1L);
        int ugly=0;
        for(int i=0;i<n;i++){
            long curr=heap.top();
            heap.pop();
            ugly = (int) curr;
            for(auto factor:factors){
                long next =curr*factor;
                if(!seen.count(next)){
                    seen.emplace(next);
                    heap.emplace(next);
                }
            }
        }
        return ugly;
    }

};

// 无疑问超时
// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         int bk=1;
//         int i=1;
//         while(i<=n){
//             while(!isUgly(bk)){
//                 bk++;
//             }
//             i++;
//             bk++;
//         }
//         return --bk;
//     }

//     bool isUgly(int m){
//         vector<int> y={2,3,5};
//         for(auto k:y){
//             while(m%k==0){
//                 m=m/k;
//             }
//         }
//         return m==1;
//     }
// };
// @lc code=end
