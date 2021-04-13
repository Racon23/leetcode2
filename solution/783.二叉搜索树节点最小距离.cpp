// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include "commoncppproblem783.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
 *
 * https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (56.31%)
 * Likes:    133
 * Dislikes: 0
 * Total Accepted:    32.8K
 * Total Submissions: 57.2K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
 * 
 * 注意：本题与
 * 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
 * 相同
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [4,2,6,1,3]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,0,48,null,null,12,49]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [2, 100] 内
 * 0 
 * 
 * 
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int minDiffInBST(TreeNode *root)
    {
        int ans = INT_MAX;
        TreeNode *p1, *p2;
        p1 = root;
        int pre = INT_MIN/2;
        while (p1)
        {
            p2 = p1->left;
            if (p2)
            {
                while (p2->right && p2->right != p1)
                {
                    p2 = p2->right;
                }
                if (!p2->right)
                {
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                }
                else
                {
                    p2->right = nullptr;
                    //exe 中右
                    ans = min(ans, abs(p1->val - pre));
                    pre = p1->val;
                }
            }
            else
            {
                //exe 最左
                ans = min(ans, abs(p1->val - pre));
                pre = p1->val;
            }
            p1 = p1->right;
        }
        return ans;
    }
};
// @lc code=end
