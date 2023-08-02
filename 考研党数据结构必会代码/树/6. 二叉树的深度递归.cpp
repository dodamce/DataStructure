// C++递归计算二叉树的深度
#include "../debug.hpp"

int deep(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = deep(root->left);
    int right = deep(root->right);
    return max(left, right) + 1;
}

int main(int argc, char const *argv[])
{
    BTree tree({1, 2, 3, 4, 5, 6});
    tree.PrintTree();
    cout << deep(tree.root) << endl;
    return 0;
}
