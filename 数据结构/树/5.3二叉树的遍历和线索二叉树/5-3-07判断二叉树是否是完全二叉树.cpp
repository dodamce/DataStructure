//层序遍历，遇到空节点看后面是否出现非空节点，如果出现了说明这个二叉树不是完全二叉树

#include "GetTreeByVector.h"
#include <queue>

using namespace std;

bool isCompleteTree(TreeNode *root)
{
    if (nullptr == root)
        return true;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node != nullptr)
        {
            q.push(node->left);
            q.push(node->right);
        }
        else
        {
            //此时队列应该全部是空节点
            while (!q.empty())
            {
                TreeNode *node = q.front();
                q.pop();
                if (node != nullptr)
                    return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    MyTree tree({1, 2, 3, 4, 5, 6});
    tree.Print();
    cout << isCompleteTree(tree.root);
    return 0;
}
