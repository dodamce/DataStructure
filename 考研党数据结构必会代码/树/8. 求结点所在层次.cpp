#include "../debug.hpp"
#include <stack>

struct Data
{
    TreeNode *node;
    bool flag;
    Data(TreeNode *_node, bool _flag = false) : node(_node), flag(_flag) {}
};

int LayerNode(TreeNode *node, int target)
{
    stack<Data *> nodes;
    // 后续遍历
    while (!nodes.empty() || node != nullptr)
    {
        while (node != nullptr)
        {
            nodes.push(new Data(node));
            node = node->left;
        }
        Data *data = nodes.top();
        nodes.pop();

        node = data->node;
        bool flag = data->flag;

        delete data;
        if (flag == false)
        {
            nodes.push(new Data(node, true));
            node = node->right;
        }
        else
        {
            if (node->val == target)
            {
                return nodes.size() + 1;
            }
            else
            {
                node = nullptr;
            }
        }
    }
    return 0; // 没找到对应的节点
}

int main(int argc, char const *argv[])
{
    BTree tree({1, 2, 3, 4, 5});
    tree.PrintTree();
    cout << LayerNode(tree.root, 4) << endl;
    return 0;
}
