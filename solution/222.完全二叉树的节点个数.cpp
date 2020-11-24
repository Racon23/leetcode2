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
// 队列全遍历
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (!root)
            return 0;
        int count = 0;
        q.emplace(root);
        TreeNode *p;
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            count++;
            if (p->left)
                q.emplace(p->left);
            if (p->right)
                q.emplace(p->right);
        }
        return count;
    }
};
// @lc code=end
