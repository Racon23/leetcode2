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
// 回溯
class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<int> temp;
        if (k == 0)
            return temp;
        vector<int> ans(k, -1);
        backTrace(nums1, nums2, k, 0, 0, 0, temp, ans);
        return ans;
    }

    void backTrace(vector<int> &nums1, vector<int> &nums2, int k, int i1, int i2, int count, vector<int> &temp, vector<int> &ans)
    {
        if (count == k)
        {
            int num = 0;
            int bGreat = 0;
            for (int i = 0; i < k; i++)
            {
                if (temp[i] < ans[i])
                {
                    bGreat = 0;
                    break;
                }
                else if (temp[i] > ans[i])
                {
                    bGreat = 1;
                    break;
                }
            }
            if (bGreat == 1)
            {
                // 复制过去
                for (int i = 0; i < k; i++)
                {
                    ans[i] = temp[i];
                }
            }
            return;
        }
        else
        {
            for (int i = i1; i < nums1.size(); i++)
            {
                temp.emplace_back(nums1[i]);
                backTrace(nums1, nums2, k, i + 1, i2, count + 1, temp, ans);
                temp.pop_back();
            }
            for (int i = i2; i < nums2.size(); i++)
            {
                temp.emplace_back(nums2[i]);
                backTrace(nums1, nums2, k, i1, i + 1, count + 1, temp, ans);
                temp.pop_back();
            }
        }
        return;
    }
};
// @lc code=end
