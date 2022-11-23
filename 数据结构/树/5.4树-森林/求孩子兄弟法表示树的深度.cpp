#include "./孩子兄弟表示法/Tree.h"

#include <algorithm>

using namespace std;

int TreeDeep(TreeNode *node)
{
    if (node == nullptr)
        return 0;
    int left = TreeDeep(node->child);
    int right = TreeDeep(node->brother);
    return std::max(left, right) + 1;
}

int main(int argc, char const *argv[])
{
    Tree tree;
    cout << "前序遍历:" << endl;
    tree.PreDisplay();
    cout << "\n"
         << TreeDeep(tree.root) << endl;
    return 0;
}
