#include "GetTreeByVector.h"

using namespace std;

int countNode(TreeNode *tree)
{
    int ret = 0;
    if (tree == nullptr)
    {
        return 0;
    }
    if (tree->left != nullptr && tree->right != nullptr)
    {
        ret += 1;
    }
    int left = countNode(tree->left);
    int right = countNode(tree->right);
    return ret + left + right;
}

int main()
{
    // MyTree tree({1, 2, 3, 4, 5, 6, 7});
    MyTree tree({1});
    tree.Print();
    cout << countNode(tree.root);
    return 0;
}