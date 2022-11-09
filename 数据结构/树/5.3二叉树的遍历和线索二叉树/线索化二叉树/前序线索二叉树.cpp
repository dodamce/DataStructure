#include "CreatTree.h"

using namespace std;

//前序线索二叉树
void PreorderSpan(TreeNode *root, TreeNode *&prev)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr)
    {
        root->left = prev;
        root->ltag = 1;
    }
    if (prev != nullptr && prev->right == nullptr)
    {
        prev->right = root;
        prev->rtag = 1;
    }
    prev = root;

    //因为是先修改的Node的tag,所以这里需要判断tag，否则会出现死循环
    if (root->ltag == 0)
        PreorderSpan(root->left, prev);
    if (root->rtag == 0)
        PreorderSpan(root->right, prev);
}

TreeNode *PreorderSpan(TreeNode *&root)
{
    TreeNode *prev = nullptr;
    TreeNode *ret = root;
    root = nullptr;
    PreorderSpan(ret, prev);
    return ret;
}

void DisplayTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    while (root != nullptr)
    {
        while (root->ltag == 0)
        {
            cout << root->data << " ";
            root = root->left;
        }
        cout << root->data << " ";
        root = root->right;
    }
}

void Destroy(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    while (root != nullptr)
    {
        while (root->ltag == 0)
        {
            TreeNode *next = root->left;
            delete root;
            root = next;
        }
        TreeNode *next = root->right;
        delete root;
        root = next;
    }
}

int main(int argc, char const *argv[])
{
    Tree tree({2, 4, 1, 5, 2, 6, 7, 3, 1, 0, 9});
    tree.InodesDisplay();
    TreeNode *node = PreorderSpan(tree.root);
    DisplayTree(node);
    Destroy(node);
    return 0;
}
