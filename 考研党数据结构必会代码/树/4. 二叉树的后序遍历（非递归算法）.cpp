#include "../debug.hpp"
#include <stack>
using namespace std;
void PostOrderTraverse(TreeNode *node)
{
    stack<TreeNode *> nodes;
    stack<bool> flags;
    while (!nodes.empty() || node != nullptr)
    {
        while (node != nullptr)
        {
            nodes.push(node);
            flags.push(false);
            node = node->left;
        }
        node = nodes.top();
        nodes.pop();
        bool flag = flags.top();
        flags.pop();
        if (flag == false)
        {
            // 不能访问这个节点，但是下次就可以访问这个节点
            nodes.push(node);
            flags.push(true);
            node = node->right;
        }
        else
        {
            cout << node->val << " ";
            node = nullptr; // 获取栈下一个元素，相当于向上递归
        }
    }
}

int main(int argc, char const *argv[])
{
    BTree tree({2, 3, 4, 1, 5});
    tree.PrintTree();
    PostOrderTraverse(tree.root);
    return 0;
}
