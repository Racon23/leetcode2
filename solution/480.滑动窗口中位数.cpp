// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include "commoncppproblem480.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 */

// @lc code=start
class Solution
{

    // 默认less降序，堆顶时最大值
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

    int ssize;
    int lsize;
    unordered_map<int, int> delay;

public:
    template <typename T>
    void prune(T &heap)
    {
        while (!heap.empty())
        {
            int top = heap.top();
            if (delay.count(top))
            {
                delay[top]--;
                if (!delay[top])
                {
                    delay.erase(top);
                }
                heap.pop();
            }
            else
            {
                break;
            }
        }
    }

    void erase(int num)
    {
        delay[num]++;
        if (num <= small.top())
        {
            ssize--;
            if (num == small.top())
                prune(small);
        }
        else
        {
            lsize--;
            if (num == large.top())
                prune(large);
        }
        makeBalance();
    }

    void makeBalance()
    {
        if (ssize - lsize >= 2)
        {
            int top = small.top();
            small.pop();
            large.emplace(top);
            ssize--;
            lsize++;
            prune(small);
        }
        else if (ssize - lsize <= -1)
        {
            int top = large.top();
            large.pop();
            small.emplace(top);
            ssize++;
            lsize--;
            prune(large);
        }
    }

    void insert(int num)
    {
        if (ssize == 0 || num <= small.top())
        {
            small.emplace(num);
            ssize++;
        }
        else
        {
            large.emplace(num);
            lsize++;
        }
        makeBalance();
    }
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        ssize = 0;
        lsize = 0;
        vector<double> ans;

        for (int i = 0; i < n; i++)
        {
            insert(nums[i]);
            if (ssize + lsize == k)
            {
                double d = 0;
                if ((k & 1) == 1)
                {
                    d = small.top() * 1.0;
                }
                else
                {
                    long long stop = small.top();
                    long long ltop = large.top();
                    d = (stop + ltop) / 2.0;
                }
                ans.emplace_back(d);
                erase(nums[i - k + 1]);
            }
        }
        return ans;
    }
};
// @lc code=end
