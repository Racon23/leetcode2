// @before-stub-for-debug-begin
#include <vector>
#include <string>
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

    void travelsal1(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        travelsal1(root->left);
        travelsal1(root->right);
        vec.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        // vector<int> vec;
        vec.clear();
        // vec.push_back(root->val);
        travelsal1(root);
        return vec;
    }
};
// @lc code=end
