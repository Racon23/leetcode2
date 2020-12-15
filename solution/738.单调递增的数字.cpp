// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem738.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 *
 * https://leetcode-cn.com/problems/monotone-increasing-digits/description/
 *
 * algorithms
 * Medium (44.45%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    10.7K
 * Total Submissions: 22.8K
 * Testcase Example:  '10'
 *
 * 给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。
 * 
 * （当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）
 * 
 * 示例 1:
 * 
 * 输入: N = 10
 * 输出: 9
 * 
 * 
 * 示例 2:
 * 
 * 输入: N = 1234
 * 输出: 1234
 * 
 * 
 * 示例 3:
 * 
 * 输入: N = 332
 * 输出: 299
 * 
 * 
 * 说明: N 是在 [0, 10^9] 范围内的一个整数。
 * 
 */

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string nstr = to_string(N);
        int i=1;
        int len = nstr.length();
        // 找到i-1>i的下标
        while(i<len&&nstr[i-1]<=nstr[i]){
            i++;
        }
        if(i<len){
            // 将i前的数逐个减，减之后可能会影响，所以要依次减
            while(i>0&&nstr[i-1]>nstr[i]){
                nstr[i-1]--;
                i--;
            }
            // 将最后符合的i后面的置9
            for(i+=1;i<len;i++){
                nstr[i]='9';
            }
        }
        return stoi(nstr);
    }
};
// @lc code=end

