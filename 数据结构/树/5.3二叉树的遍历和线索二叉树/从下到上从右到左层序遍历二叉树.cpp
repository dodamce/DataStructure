//先按照正常的层序遍历，利用队列保存节点，出队列时将节点放到栈上。

//最后从栈上弹出节点输出即可

#include "GetTreeByVector.h"
#include <queue>
#include <stack>
#include <assert.h>

using namespace std;

void displayTree(TreeNode *root)
{
    assert(root != nullptr);
    queue<TreeNode *> q;
    stack<TreeNode *> st;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
        st.push(node);
        q.pop();
    }

    //出栈并打印
    while (!st.empty())
    {
        TreeNode *node = st.top();
        st.pop();
        cout << node->val << " ";
    }
}

int main(int argc, char const *argv[])
{
    MyTree tree({1, 2, 3, 4, 5, 6, 7});
    tree.Print();
    displayTree(tree.root);
    return 0;
}
