// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem992.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=992 lang=cpp
 *
 * [992] K 个不同整数的子数组
 */

// @lc code=start
class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &A, int K)
    {
        return atMost(A,K)-atMost(A,K-1);
    }

    int atMost(vector<int> &A, int K){
        int n = A.size();
        vector<int> freq(n+1); // 整数频率
        int left=0,right=0;
        int ans=0;
        int count =0; // 整数种数
        while(right<n){
            if(freq[A[right]]==0){
                count++;
            }
            freq[A[right]]++;
            right++;

            while(count>K){
                freq[A[left]]--;
                if(freq[A[left]]==0){
                    count--;
                }
                left++;
            }
            
            // 以left为起点最多K个 [1,2,3]中[1] [1,2] [1,2,3] 3个
            ans+=right-left;

        }
        return ans;
    }
};
// @lc code=end
