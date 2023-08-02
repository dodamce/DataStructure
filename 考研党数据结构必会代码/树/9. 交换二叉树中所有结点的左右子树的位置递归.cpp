#include "../debug.hpp"

// 递归
TreeNode *ExchangeBT(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    TreeNode *left = ExchangeBT(root->left);
    TreeNode *right = ExchangeBT(root->right);
    root->left = right;
    root->right = left;
    return root;
}

int main(int argc, char const *argv[])
{
    BTree tree({1, 2, 3, 4, 5});
    tree.PrintTree();
    PrintCur print;
    print.printTree(ExchangeBT(tree.root));
    return 0;
}
