// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem144.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (68.26%)
 * Likes:    435
 * Dislikes: 0
 * Total Accepted:    214.8K
 * Total Submissions: 314.7K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [1,2,3]
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        TreeNode *p1 = root, *p2;
        vector<int> res;
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
                    // exe
                    res.emplace_back(p1->val);
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                }
                else
                {
                    p2->right = nullptr;
                }
            }
            else
            {
                // 最左节点
                //exe
                res.emplace_back(p1->val);
            }
            // 当最左节点空 和 该节点已经连接过时，移到右

            p1 = p1->right;
        }
        // exe p1->right
        return res;
    }
};
// @lc code=end
