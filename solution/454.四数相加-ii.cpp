// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem454.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
// 哈希表
class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        unordered_map<int,int> m1;
        int n = A.size();
        int ans = 0;

        for(auto &u:A){
            for(auto &v:B){
                m1[u+v]++;
            }
        }

        for(auto &u:C){
            for(auto &v:D){
                if(m1.count(-u-v)){
                    ans += m1[-u-v];
                }
            }
        }
        return ans;
    }
};
// @lc code=end
