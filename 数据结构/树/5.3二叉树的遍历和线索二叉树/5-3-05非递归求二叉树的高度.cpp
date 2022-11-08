#include "GetTreeByVector.h"
#include <queue>
#include <math.h>

using namespace std;

//非递归求二叉树高度
int getTreeHeight(TreeNode *root)
{
    int level = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int maxcount = pow(2, level);
        for (int i = 0; i < maxcount && !q.empty(); i++)
        {
            TreeNode *node = q.front();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            q.pop();
        }
        if (q.empty())
            return level + 1;
        level++;
    }
    return -1;
}

//递归求二叉树高度
int getTreeHeightNotQueue(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left = getTreeHeightNotQueue(root->left);
    int right = getTreeHeightNotQueue(root->right);
    return max(left, right) + 1;
}

int main(int argc, char const *argv[])
{
    MyTree tree({1, 2, 3, 4, 5, 6, 7, 8});
    tree.Print();
    // cout << getTreeHeight(tree.root);
    cout << getTreeHeightNotQueue(tree.root);
    return 0;
}
