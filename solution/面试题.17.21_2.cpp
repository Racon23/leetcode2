#include <algorithm>
#include <vector>

using namespace std;
// 双指针
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int leftmax =0;
        int rightmax =0;
        int left =0;
        int right = n-1;
        int ans =0;
        while (left<right)
        {
            leftmax = max(leftmax,height[left]);
            rightmax = max(rightmax,height[right]);
            if(height[left]<height[right]){
                ans += leftmax - height[left];
                left++;
            }else{
                ans += rightmax - height[right];
                right--;
            }
        }
        return ans;
    }
};