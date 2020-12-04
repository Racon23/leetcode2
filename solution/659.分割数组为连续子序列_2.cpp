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
// 贪心
class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        int len = nums.size();
        
        unordered_map<int,int> countMap;
        unordered_map<int,int> endMap;

        for(auto &x:nums){
            countMap[x]++;
        }

        for(auto&x:nums){
            int count = countMap[x];
            if(count>0){
                int prevEndCount = endMap[x-1];
                if(prevEndCount>0){
                    endMap[x-1]--;
                    endMap[x]++;
                    countMap[x]--;
                }else{
                    int count1 = countMap[x+1];
                    int count2 = countMap[x+2];
                    if(count1>0&&count2>0){
                        countMap[x+1]--;
                        countMap[x+2]--;
                        countMap[x]--;
                        endMap[x+2]++;
                    }else{
                        return false;
                    }
                }
            }
        }


        return true;
    }
};
// @lc code=end
