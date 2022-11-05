//为了实现思想，这里选择leetcode的题
// https://leetcode.cn/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/

//  Definition for a binary tree node.

#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root == p)
        {
            return p;
        }
        else if (root == q)
        {
            return q;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);//找左子树
        TreeNode *right = lowestCommonAncestor(root->right, p, q);//找右子树
        if (left != nullptr && right != nullptr)
        {
            return root;
        }
        else if (left == nullptr)
        {
            return right;
        }
        return left;
    }
};