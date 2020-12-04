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
        int n = nums.size();
        int dp1=0,dp2=0,dp3=0;
        int i=0;
        while(i<n){
            int start = i;
            int x = nums[i];
            // 计数重复
            while(i<n&&nums[i]==x){
                i++;
            }
            int cnt = i-start;

            if(start>0&&x!=nums[start-1]+1){
                if(dp1+dp2>0){
                    return false;
                }else{
                    dp1 = cnt;
                    dp2=dp3=0;
                }
            }else{
                if(dp1+dp2>cnt) return false;
                int left = cnt-dp1-dp2; //优先让dp1和dp2消耗
                int keep = min(dp3,left); // 剩余的满足dp3，再剩余的赋值dp1
                dp3 = keep+dp2;
                dp2 = dp1;
                dp1 = left-keep;
            }
        }

        return dp1==0&&dp2==0;
    }
};
// @lc code=end
