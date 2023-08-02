#include "../debug.hpp"
#include <stack>

void Destroy(TreeNode *node)
{
    if (node == nullptr)
        return;
    Destroy(node->left);
    Destroy(node->right);
    delete node;
}

TreeNode *DeleteSubtree(TreeNode *root, int val)
{
    TreeNode *node = root;
    stack<TreeNode *> nodes;
    TreeNode *parent = nullptr;
    while (!nodes.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            if (root->val == val)
            {
                if (parent == nullptr)
                {
                    // 全部删除
                    Destroy(root);
                    return nullptr;
                }
                else
                {
                    Destroy(root->left);
                    Destroy(root->right);
                    if (parent->left == root)
                    {
                        parent->left = nullptr;
                    }
                    else
                    {
                        parent->right = nullptr;
                    }
                    return node;
                }
            }
            nodes.push(root);
            parent = root;
            root = root->left;
        }
        parent = nodes.top();
        nodes.pop();
        root = parent->right;
    }
    return root;
}

int main(int argc, char const *argv[])
{
    BTree tree({1, 2, 3, 4, 5, 6, 7});
    tree.PrintTree();
    PrintCur print;
    print.printTree(DeleteSubtree(tree.root, 3));
    cout << "end" << endl;
    return 0;
}
