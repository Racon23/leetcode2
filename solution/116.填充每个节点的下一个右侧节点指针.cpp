// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem116.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
        {
            return root;
        }
        Node *leftmost = root->left, *head = root;
        while (leftmost)
        {
            if (head)
            {
                head->left->next = head->right;
                if (head->next)
                {
                    head->right->next = head->next->left;
                }
                head = head->next;
            }
            else
            {
                head = leftmost;
                leftmost = head->left;
            }
        }
        return root;
    }
};
// @lc code=end
