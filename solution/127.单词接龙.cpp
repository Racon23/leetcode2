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
// 可变单词遍历
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size();
        int m = beginWord.size();
        unordered_set<string> visited1;
        unordered_set<string> visited2;
        queue<string> q1; // 正向bfs
        queue<string> q2; // 反向bfs
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

        // 单词列表转换为字典
        unordered_set<string> wdset;
        for (auto &it : wordList)
        {
            wdset.emplace(it);
        }
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
                for (int j = 0; j < m; j++)
                {
                    char tc = s[j];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        s[j] = c;
                        if (visited1.find(s) != visited1.end())
                        {
                            continue;
                        }
                        if (visited2.find(s) != visited2.end())
                        {
                            return count + 1;
                        }
                        if (wdset.find(s))
                        {
                            q1.emplace(s);
                            visited1.emplace(s);
                        }
                    }
                    s[j] = tc;
                }
            }
            len1 = q1.size();
            len2 = q2.size();
        }
        return 0;
    }

};
// @lc code=end
