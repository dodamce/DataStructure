/**
 * @file 7-3-11递归logN找二叉排序树第k小的元素.cpp
 * @author dodamce (3030949391@qq.com)
 * @brief
 * 编写一个递归算法，在一棵有n个结点的、随机建立起来的二叉排序树上查找第A: （ 1 <k<n ）小的元素，并返回指向该结点的指针。
 * 要求算法的平均时间复杂度为O（logN）。
 * 二叉排序树的每个结点中除data, lchild, rchild等数据成员外，增加一个count成员，保存以该结点为根的子树上的结点个数。
 * @version 0.1
 * @date 2023-02-27
 *
 * @copyright Copyright (c) 20231
 *
 */

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    int count;
};

TreeNode *findKSmall(TreeNode *node, int k)
{
    if (k < 1 || k > node->count)
    {
        return nullptr;
    }
    if (node->left == nullptr)
    {
        if (node->count == 1)
        {
            return node;
        }
        else if (node->count > 1)
        {
            // 第k小的节点在树右边
            return findKSmall(node->right, k - 1);
        }
    }
    else
    {
        if (k - 1 == node->left->count)
        {
            return node;
        }
        if (k - 1 < node->left->count)
        {
            // 第k小的节点在node的左边
            return findKSmall(node->left, k);
        }
        else if (k - 1 > node->left->count)
        {
            // 第k小的系欸但在node的右子树上,找右子树上第k - (node->left->count + 1)节点
            return findKSmall(node->right, k - (node->left->count + 1));
        }
    }
}

int main(int argc, char const *argv[])
{
    // 因为这里没有实现带count的树，就不进行案例测试了
    return 0;
}
