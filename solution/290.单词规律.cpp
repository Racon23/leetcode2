// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem290.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (43.97%)
 * Likes:    244
 * Dislikes: 0
 * Total Accepted:    45.5K
 * Total Submissions: 101.3K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        int pl = pattern.length();
        int sl = s.length();
        // if(pl!=sl){
        //     return false;
        // }
        int last = 0; //上一个单词下标
        int j = 0;    //空格下标
        string sp;
        for (int i = 0; i < pl; i++)
        {
            if (j > sl)
                return false;
            while (j < sl && s[j] != ' ')
            {
                j++;
            }
            sp = s.substr(last, j - last);
            j++;
            last = j;
            if (mp1.find(pattern[i]) == mp1.end() && mp2.find(sp) == mp2.end())
            {
                mp1[pattern[i]] = sp;
                mp2[sp] = pattern[i];
            }
            else if (mp1.find(pattern[i]) != mp1.end() && mp2.find(sp) != mp2.end())
            {
                if (mp1[pattern[i]] != sp && mp2[sp] != pattern[i])
                {
                    return false;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                return false;
            }
        }
        return last - 1 == sl;
    }
};
// @lc code=end
