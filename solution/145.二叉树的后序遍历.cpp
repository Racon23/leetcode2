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
class Solution
{
    vector<int> vec;

    void exeNode(TreeNode *node)
    {
        vec.push_back(node->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        TreeNode *node;
        TreeNode *lnode;
        stack<TreeNode *> stk;
        node = root;
        vec.clear();
        // node = nullptr;
        while (node)
        {
            while (node->left)
            {
                stk.emplace(node);
                node = node->left;
            }
            if (node->right)
            {
                //2 最左节点的右节点不空，继续找最底层最左
                stk.push(node);
                node = node->right;
            }
            else
            {
                //3 空，抵达最底层最左
                exeNode(node);
                lnode = node;
                node = stk.top();
                //4 返回根
                while (lnode == node->right)
                {
                    exeNode(node);
                    stk.pop();
                    lnode = node;
                    node = stk.top();
                }
                if (node)
                    node = node->right;
            }
        }
        return vec;
    }
};
// @lc code=end
