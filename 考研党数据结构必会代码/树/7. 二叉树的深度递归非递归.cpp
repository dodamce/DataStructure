// C++递归计算二叉树的深度
#include "../debug.hpp"
#include <stack>
using namespace std;
struct Data
{
    TreeNode *node;
    int deep;
    Data(TreeNode *_node, int _deep) : node(_node), deep(_deep) {}
};

int deep(TreeNode *root)
{
    stack<Data *> nodes;
    if (root == nullptr)
    {
        return 0;
    }
    int curDeep = 1;
    int deep = 1;
    while (!nodes.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            nodes.push(new Data(root, curDeep));
            root = root->left;
            curDeep += 1;
        }
        Data *data = nodes.top();
        nodes.pop();

        root = data->node;
        curDeep = data->deep;
        if (root->left == nullptr && root->right == nullptr)
        {
            deep = max(deep, curDeep);
        }
        root = root->right;
        curDeep += 1;
    }
    return deep;
}

int main(int argc, char const *argv[])
{
    BTree tree({1, 2, 3, 4, 5, 6});
    tree.PrintTree();
    cout << deep(tree.root) << endl;
    return 0;
}
