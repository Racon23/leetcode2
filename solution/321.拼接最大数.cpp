// @before-stub-for-debug-begin
#include <vector>
#include <string>

#include "commoncppproblem321.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ret;
        if (m == 0 && n == 0 || k == 0)
            return ret;

        vector<pair<int, int>> spt;
        // 合并两数组
        int i = 0, j = 0;
        while (i < m || j < n)
        {
            if (i >= m)
            {
                spt.emplace_back(nums2[j], j + m);
                j++;
            }
            else if (j >= n)
            {
                spt.emplace_back(nums1[i], i);
                i++;
            }
            else
            {
                if (nums1[i] >= nums2[j])
                {
                    spt.emplace_back(nums1[i], i);
                    i++;
                }
                else
                {
                    spt.emplace_back(nums2[j], j + m);
                    j++;
                }
            }
        }

        int count = m+n;
        i = 0;
        while(count>k){
            // 找到可以抽掉的数，最后一位或者刚好小于后面一位
            while(i<m+n-1||spt[i].first>spt[i+1].first){
                i++;
            }
            // 抽掉后判断能否重铸，只要前面有另一个数组的比它小的就可以
            // 把当前位置同一数组的数，抽到非本数组而且小于它的最前面，直到非本数组
            spt[i]

            // 重铸后，i-1
            // 不重铸就继续找i+1

        }

        return ret;
    }
};
// @lc code=end
