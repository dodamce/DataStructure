#include "../debug.hpp"
#include <queue>
#include <algorithm>
// 非递归
TreeNode *ExchangeBT(TreeNode *root)
{
    queue<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty())
    {
        TreeNode *node = nodes.front();
        nodes.pop();
        swap(node->left, node->right);
        if (node->left != nullptr)
            nodes.push(node->left);
        if (node->right != nullptr)
            nodes.push(node->right);
    }
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
