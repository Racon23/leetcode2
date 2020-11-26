// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem164.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
// 桶排序
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;
        int ans = 0;

        vector<int> spt(n);
        int maxnum = *max_element(nums.begin(), nums.end());
        int d = 0; //计算有多少位
        while (maxnum > 0)
        {
            maxnum /= 10;
            d++;
        }
        vector<int> count(10);
        int scale = 1;
        int t;
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < 10; j++)
                count[j] = 0; //每次分配前清空计数器

            for (int j = 0; j < n; j++)
            {
                t = (nums[j] / scale) % 10;
                count[t]++; // 计算个数
            }

            for (int j = 1; j < 10; j++)
            {
                count[j] += count[j - 1]; // 累加得到各个数的位置
            }

            for (int j = n - 1; j >= 0; j--)
            {
                // 倒序填充可结合count数组，按位置填充
                t = (nums[j] / scale) % 10;
                spt[count[t]-1] = nums[j];
                count[t]--;
            }
            for(int j=0;j<n;j++){
                nums[j]=spt[j]; //复制
            }
            scale*=10;
        }

        for (int i = 1; i < n; i++)
        {
            ans = max(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};
// @lc code=end
