#include "../debug.hpp"
#include <queue>
using namespace std;
void LayeredOrderTraverse(TreeNode *root)
{
    queue<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty())
    {
        int size = nodes.size(); // 每层节点个数
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = nodes.front();
            nodes.pop();
            cout << node->val << " ";
            if (node->left)
                nodes.push(node->left);
            if (node->right)
                nodes.push(node->right);
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    BTree tree({4, 3, 5, 6, 3, 1});
    tree.PrintTree();
    LayeredOrderTraverse(tree.root);
    return 0;
}
