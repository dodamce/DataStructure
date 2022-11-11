#include "GetTreeByVector.h"

//后序递归
TreeNode *swapNode(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;
    TreeNode *left = swapNode(root->left);
    TreeNode *right = swapNode(root->right);
    root->left = right;
    root->right = left;
    return root;
}

int main()
{
    MyTree tree({1, 2, 3, 4, 5, 6, 7});
    tree.Print();
    swapNode(tree.root);
    tree.Print();
    return 0;
}