#include "./孩子兄弟表示法/Tree.h"

//本质上就是求二叉树也叶子节点
int Leaves(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    if (node->child == nullptr && node->brother == nullptr)
    {
        return 1;
    }
    int left = Leaves(node->child);
    int right = Leaves(node->brother);
    return left + right;
}

int main(int argc, char const *argv[])
{
    Tree tree;
    tree.PreDisplay();
    std::cout << Leaves(tree.root) << "\n";
    return 0;
}
