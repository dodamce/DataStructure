#include <iostream>
// #include "./搜索二叉树/SearchTree.h"
#include <vector>

#include "../../树/5.3二叉树的遍历和线索二叉树/CreatTree.h"

using namespace std;

// bool isSearchTree(SearchTree &tree)
// {
//     return tree.isSearchTree();
// }

// 获取搜索二叉树的最小值
size_t getMin(Tree &tree)
{
    TreeNode *node = tree.root;
    if (node == nullptr)
    {
        return -1;
    }
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node->data;
}

// 获取搜索二叉树的最大值
size_t getMax(Tree &tree)
{
    TreeNode *node = tree.root;
    if (node == nullptr)
    {
        return -1;
    }
    while (node->right != nullptr)
    {
        node = node->left;
    }
    return node->data;
}

bool _isSearchTree(TreeNode *root, size_t min, size_t max)
{
    if (root == nullptr)
        return true;

    if (root->data < min || root->data > max)
        return false;

    return _isSearchTree(root->left, min, root->data - 1) && _isSearchTree(root->right, root->data + 1, max);
}

bool isSearchTree(Tree &tree)
{
    return _isSearchTree(tree.root, getMin(tree), getMax(tree));
}

int main(int argc, char const *argv[])
{
    vector<int> ret = {1, 2, 3, 4};
    // SearchTree tree(ret);
    // cout << isSearchTree(tree) << endl;
    return 0;
}
