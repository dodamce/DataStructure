#include "GetTreeByVector.h"

//删除node的子树
void Del(TreeNode *&node)
{
    if (node == nullptr)
        return;
    Del(node->left);
    Del(node->right);
    delete node;
    node = nullptr;
}

void DelElem(TreeNode *&root, int target)
{
    if (root == nullptr)
    {
        return;
    }
    DelElem(root->left, target);
    DelElem(root->right, target);
    if (root->val == target)
    {
        Del(root);
    }
}

int main()
{
    MyTree tree({1, 2, 3, 4, 5});
    tree.Print();
    DelElem(tree.root, 1);
    tree.Print();
    return 0;
}