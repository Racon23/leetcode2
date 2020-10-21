// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem28.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.65%)
 * Likes:    601
 * Dislikes: 0
 * Total Accepted:    247.2K
 * Total Submissions: 623.5K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */

// @lc code=start
// 优化后
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())return 0;
        int i=0,m=haystack.size();//文本指针i用来指示文本串
        int j=0,n=needle.size();//模式指针j用来指示模式串
        vector<int> nextVal=get_nextVal(needle);
        while(i<m&&j<n){
            if(j==-1||needle[j]==haystack[i])i++,j++;
            else j=nextVal[j];
        }
        return j==n?i-j:-1;
    }

    //普通：get_next
    vector<int> get_next(const string& pat){
        int n=pat.size();
        vector<int> next(n+1,-1);//这里数组大小为n+1，要算上pat[n-1]
        int k=-1,j=0;
        while(j<n){
            if(k==-1||pat[k]==pat[j])next[++j]=++k;//k，j指针都右移一位
            else k=next[k];//后缀指针k回退到next[k]（下标）的位置
        }
        return next;
    }

    //优化：get_nextVal
    vector<int> get_nextVal(const string& pat){
        int n=pat.size();
        vector<int> nextVal(n,-1);//这里next数组大小为n，已经算上pat[n-1]了
        int k=-1,j=0;
        while(j<n-1){
            if(k==-1||pat[k]==pat[j]){
                k++,j++;
                if(pat[j]!=pat[k])nextVal[j]=k;
                else nextVal[j]=nextVal[k];
            }
            else k=nextVal[k];
        }
        return nextVal;
    }
};
// @lc code=end
