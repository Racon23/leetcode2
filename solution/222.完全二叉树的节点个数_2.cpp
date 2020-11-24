// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem222.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 二分
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int h = 0;
        TreeNode *node = root;
        while (node->left)
        {
            node = node->left;
            h++;
        }
        int low = (1 << h), high = (1 << h + 1) - 1;
        int mid;
        while (low < high)
        {
            mid = (low + high + 1) / 2;
            if (existNode(root, h, mid))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }

    bool existNode(TreeNode *root, int h, int k)
    {
        int bits = 1 << (h - 1);
        TreeNode *node = root;
        while (node && bits > 0)
        {
            if ((bits & k) == 0)
                node = node->left;
            else
                node = node->right;
            bits >>= 1;
        }
        return node != nullptr;
    }
};
// @lc code=end
