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
// 直接反转
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
            vector<int> temp;

            for (int i = 0; i < size; i++)
            {
                auto node = nodeQueue.front();
                nodeQueue.pop();

                temp.push_back(node->val);

                if (node->left)
                {
                    nodeQueue.push(node->left);
                }
                if (node->right)
                {
                    nodeQueue.push(node->right);
                }
            }
            if(!isLeft){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
            isLeft = !isLeft;
        }
        return ans;
    }
};
// @lc code=end
