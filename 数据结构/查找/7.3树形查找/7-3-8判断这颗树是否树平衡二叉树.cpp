#include "./平衡二叉树/BalanceTree.h"

#include <algorithm>

// 获取搜索二叉树的最小值
size_t getMin(BalanceTree &tree)
{
    Node *node = tree.root;
    if (node == nullptr)
    {
        return -1;
    }
    while (node->_left != nullptr)
    {
        node = node->_left;
    }
    return node->_val;
}

// 获取搜索二叉树的最大值
size_t getMax(BalanceTree &tree)
{
    Node *node = tree.root;
    if (node == nullptr)
    {
        return -1;
    }
    while (node->_right != nullptr)
    {
        node = node->_left;
    }
    return node->_val;
}

bool _isSearchTree(Node *root, size_t min, size_t max)
{
    if (root == nullptr)
        return true;

    if (root->_val < min || root->_val > max)
        return false;

    return _isSearchTree(root->_left, min, root->_val - 1) && _isSearchTree(root->_right, root->_val + 1, max);
}

bool CheckVal(BalanceTree &tree)
{
    return _isSearchTree(tree.root, getMin(tree), getMax(tree));
}

// 首先AVL树要先满足搜索二叉树，其次是满足其高度要求
int Height(Node *root)
{
    if (root == nullptr)
        return 0;

    int left = Height(root->_left);
    int right = Height(root->_right);
    return std::max(left, right) + 1;
}
bool _CheckHeight(Node *root)
{
    if (root == nullptr)
        return true;

    int left = Height(root->_left);
    int right = Height(root->_right);

    if (abs(right - left) >= 2)
    {
        return false;
    }

    return _CheckHeight(root->_left) && _CheckHeight(root->_right);
}

bool CheckHeight(BalanceTree &tree)
{
    return _CheckHeight(tree.root);
}

bool isAVLBalanceTree(BalanceTree &tree)
{
    return CheckVal(tree) && CheckHeight(tree);
}

int main(int argc, char const *argv[])
{

    BalanceTree tree({1, 2, 3, 4, 5, 6, 7});
    std::cout << isAVLBalanceTree(tree) << std::endl;
    return 0;
}
