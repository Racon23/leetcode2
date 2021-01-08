// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem189.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k%n;
        int count = gcd(n,k);
        for(int start=0;start<count;start++){
            int cur = start;
            int prev = nums[cur];
            do{
                int next = (cur+k)%n;
                swap(prev,nums[next]);
                cur = next;
            }while(cur!=start);
        }
    }
};
// @lc code=end
