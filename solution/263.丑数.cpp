// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem263.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution
{
public:
    bool isUgly(int n)
    {
        if(n<=0) {
            return false;
        }
        vector<int> yin = {2, 3, 5};
        for(int i=0;i<3;i++){
            while(n%yin[i]==0){
                n/=yin[i];
            }
        }
        return n==1;
    }
};
// @lc code=end
