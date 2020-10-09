// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem145.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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

<<<<<<< HEAD
// moris解法
=======
>>>>>>> 16c8fd6f65ebbde47d4add7a607baa775ef50c8e
class Solution
{
    vector<int> vec;

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
<<<<<<< HEAD
        TreeNode *node, *prev;
        stack<TreeNode *> stk;
        node = root;
        prev = nullptr;
        while (node != nullptr || !stk.empty())
        {
            while (node != nullptr)
            {
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            if (node->right == nullptr || prev == node->right)
            {
                vec.emplace_back(node->val);
                prev = node;
                node = nullptr;
            }
            else
            {
                stk.emplace(node);
                node = node->right;
            }
        }
=======
        TreeNode *prev;
        stack<TreeNode *> stk;
        prev = nullptr;
        while (root != nullptr||!stk.empty())
        {
            while (root != nullptr)
            {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->right == nullptr || root->right == prev)
            {
                vec.emplace_back(root->val);
                prev = root;
                root = nullptr;
            }
            else
            {
                stk.emplace(root);
                root = root->right;
            }
        }

>>>>>>> 16c8fd6f65ebbde47d4add7a607baa775ef50c8e
        return vec;
    }
};
// @lc code=end
