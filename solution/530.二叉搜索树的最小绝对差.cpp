// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem530.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        TreeNode *node = root, *p1, *p2 = nullptr;
        int res = INT_MAX;
        while (node != nullptr)
        {
            p1 = node->left;
            if (p1 == nullptr)
            {
                // 抵达最左节点
                // exeNode();
                if (p2 == nullptr)
                {
                    p2 = node;
                }
                else
                {
                    res = min(res, abs(p2->val - node->val));
                    p2 = node;
                }
                node = node->right;
                continue;
            }
            while (p1->right != nullptr && p1->right != node)
            {
                p1 = p1->right;
            }
            if (p1->right == nullptr)
            {
                p1->right = node;
                node = node->left;
                continue;
            }
            else
            {
                // p1 right就是当前节点
                // exeNode();
                res = min(res, abs(p2->val - node->val));
                p2 = node;
                p1->right = nullptr;
                node = node->right;
            }
        }
        return res;
    }
};
// @lc code=end
