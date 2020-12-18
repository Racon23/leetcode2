// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem389.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 *
 * https://leetcode-cn.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (64.18%)
 * Likes:    191
 * Dislikes: 0
 * Total Accepted:    56.4K
 * Total Submissions: 83.6K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t，它们只包含小写字母。
 * 
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 * 
 * 请找出在 t 中被添加的字母。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "abcd", t = "abcde"
 * 输出："e"
 * 解释：'e' 是那个被添加的字母。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "", t = "y"
 * 输出："y"
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "a", t = "aa"
 * 输出："a"
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "ae", t = "aea"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 1000
 * t.length == s.length + 1
 * s 和 t 只包含小写字母
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> sm(26,0);
        int sl = s.length();
        int tl = t.length();
        for(int i=0;i<sl;i++){
            sm[s[i]-'a']++;
        }
        for(int i=0;i<tl;i++){
            sm[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(sm[i]<0) return 'a'+i;
        }
        return 0;
    }
};
// @lc code=end

