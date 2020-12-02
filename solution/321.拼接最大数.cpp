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
// 单调栈
class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ret(k, 0);
        int start = max(0, k - n), end = min(k, m);
        vector<int> subseq1;
        vector<int> subseq2;
        for (int i = start; i <= end; i++)
        {
            vector<int> subseq1(maxSubSequence(nums1, i));
            vector<int> subseq2(maxSubSequence(nums2, k - i));
            vector<int> mergeseq(merge(subseq1, subseq2));
            if (compare(mergeseq, 0, ret, 0) > 0)
            {
                ret.swap(mergeseq);
            }
        }
        return ret;
    }

    vector<int> maxSubSequence(vector<int> &nums, int k)
    {
        vector<int> stack(k, 0);
        int length = nums.size();
        int top = -1;
        int remain = length - k;
        for (int i = 0; i < length; i++)
        {
            int num = nums[i];
            // stk有数，而且top大于num并且nums中还有数
            while (top >= 0 && stack[top] < num && remain > 0)
            {
                top--;
                remain--;
            }
            // 当加入一个数，top才加1
            if (top < k - 1)
            {
                stack[++top] = num;
            }
            else
            {
                remain--;
            }
        }

        return stack;
    }

    vector<int> merge(vector<int> &subseq1, vector<int> &subseq2)
    {
        int x = subseq1.size();
        int y = subseq2.size();
        if (x == 0)
            return subseq2;
        if (y == 0)
            return subseq1;
        int len = x + y;
        vector<int> mergeseq(len);
        int i1 = 0, i2 = 0;
        for (int i = 0; i < len; i++)
        {
            if (compare(subseq1, i1, subseq2, i2) > 0)
            {
                mergeseq[i] = subseq1[i1++];
            }
            else
            {
                mergeseq[i] = subseq2[i2++];
            }
        }

        return mergeseq;
    }

    // >0 seq1大,==0 相等，<0 seq2大
    int compare(vector<int> &seq1, int i1, vector<int> &seq2, int i2)
    {
        int x = seq1.size();
        int y = seq2.size();
        while (i1 < x && i2 < y)
        {
            int diff = seq1[i1] - seq2[i2];
            if (diff != 0)
            {
                return diff;
            }
            i1++;
            i2++;
        }
        return (x - i1) - (y - i2);
    }
};
// @lc code=end
