// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem103.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }
        queue<TreeNode *> nodeQueue;
        bool isLeft = true;
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            deque<int> levelList;
            int size = nodeQueue.size();
            for (int i = 0; i < size; i++)
            {
                auto node = nodeQueue.front();
                nodeQueue.pop();
                if (isLeft)
                {
                    levelList.push_back(node->val);
                }
                else
                {
                    levelList.push_front(node->val);
                }
                if (node->left)
                {
                    nodeQueue.push(node->left);
                }
                if (node->right)
                {
                    nodeQueue.push(node->right);
                }
            }
            vector<int> temp;
            while(!levelList.empty())
            {
                int front = levelList.front();
                temp.push_back(front);
                levelList.pop_front();
            }
            ans.push_back(temp);
            isLeft = !isLeft;
        }
        return ans;
    }
};
// @lc code=end
