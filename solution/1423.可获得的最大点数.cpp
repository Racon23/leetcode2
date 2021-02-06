#include <vector>
#include <algorithm>

using namespace std;
/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int size = cardPoints.size();
        int st = size-k;
        int maxn =0 ;
        int sum = 0;
        for(int i=st;i<size;i++){
            sum+=cardPoints[i];
        }
        maxn = sum;

        while(st<size){
           sum= sum+cardPoints[st+k-size]-cardPoints[st];
           st++;
           maxn = max(maxn,sum);
        }
        return maxn;
    }
};
// @lc code=end
