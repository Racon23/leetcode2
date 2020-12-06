// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "commoncppproblem621.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int len = tasks.size();
        if (n == 0)
            return len;
        vector<pair<int, int>> countMap(26, {-1, 0});

        for (auto &x : tasks)
        {
            countMap[x - 'A'].first = x - 'A';
            countMap[x - 'A'].second++;
        }

        sort(countMap.begin(), countMap.end(), [](const pair<int, int> &u, const pair<int, int> &v) {
            return u.second > v.second;
        });

        int maxCount = countMap[0].second;
        int sptlen = 0;
        vector<int> spt;
        int count = 0; // 记录已填充的任务
        int rlen;

        if (maxCount * (n + 1) > len)
        {
            sptlen = maxCount * (n + 1);
            spt = vector<int>(sptlen, -1);
            int tail = (maxCount - 1) * (n + 1);
            int j = 0;
            for (int i = 0; i < 26; i++)
            {
                if (countMap[i].second == maxCount)
                {
                    spt[tail + j] = countMap[i].first;
                    countMap[i].second--;
                    j++;
                    count++;
                }else{
                    break;
                }
            }

            if ((maxCount - 1) * (n + 1) >= len - count)
            {
                rlen = tail;
            }
            else
            {
                rlen = sptlen;
            }
        }
        else
        {
            sptlen = len;
            rlen = len;
            spt = vector<int>(sptlen, -1);
        }

        // vector<int> spt(sptlen, -1);
        int part = 0; // 记录当前第几间隙
        int pos = 0;  // 记录当前间隙中的位置
        int i = 0;    // countMap下标

        while (pos <= n && count < len)
        {
            part = 0;
            while (part * (n + 1) + pos < rlen && count < len)
            {
                if(spt[part * (n + 1) + pos]!=-1) {
                    break;
                } 
                spt[part * (n + 1) + pos] = countMap[i].first;
                countMap[i].second--;
                count++;
                if (countMap[i].second == 0)
                    i++;

                part++;
            }
            pos++;
        }

        for (int i = sptlen - 1; i >= 0; i--)
        {
            if (spt[i] != -1)
                return i + 1;
        }
        return len;
    }
};
// @lc code=end
