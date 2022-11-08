#include "GetTreeByVector.h"

#include <queue>
#include <assert.h>

using namespace std;

void SequenceDisplay(TreeNode *root)
{
    assert(root != nullptr);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}

int main()
{
    MyTree tree({1, 2, 3, 4, 5});
    SequenceDisplay(tree.root);
    return 0;
}