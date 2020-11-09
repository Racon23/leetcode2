// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include "commoncppproblem127.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
// double bfs
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size();
        unordered_set<int> visited1;
        unordered_set<int> visited2;
        queue<int> q1; // 正向bfs
        queue<int> q2; // 反向bfs
        int len1;
        int len2;
        for (int i = 0; i < n; i++)
        {
            if (wordList[i] == endWord)
            {
                q2.emplace(i);
                visited2.emplace(i);
            }
        }
        if (q2.empty())
        {
            return 0;
        }
        wordList.emplace_back(beginWord);
        q1.emplace(n);
        visited1.emplace(n);
        len1 = q1.size();
        len2 = q2.size();
        int count = 0;
        while (len1 > 0 && len2 > 0)
        {
            count++;
            if (len1 > len2)
            {
                queue<int> temp = q2;
                q2 = q1;
                q1 = temp;
                len1 = len2;
                len2 = q2.size();
                unordered_set<int> tv = visited2;
                visited2 = visited1;
                visited1 = tv;
            }
            for (int i = 0; i < len1; i++)
            {
                string s = wordList[q1.front()];
                q1.pop();
                for (int j = 0; j < n; j++)
                {
                    if (visited1.find(j) != visited1.end())
                    {
                        continue;
                    }
                    if (!canConvert(s, wordList[j]))
                    {
                        continue;
                    }
                    if (visited2.find(j) != visited2.end())
                    {
                        return count + 1;
                    }
                    q1.emplace(j);
                    visited1.emplace(j);
                }
            }
            len1 = q1.size();
            len2 = q2.size();
        }
        return 0;
    }

    bool canConvert(string s1, string s2)
    {
        // if (s1.length() != s2.length())
        //     return false;
        int count = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                count++;
            }
        }
        return count == 1;
    }
};
// @lc code=end
