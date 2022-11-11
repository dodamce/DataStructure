#include "GetTreeByVector.h"

#include <stack>

using namespace std;

//先序遍历第k个节点
void DisplayKTree(TreeNode *root, int k)
{
    if (root == nullptr)
        return;

    stack<TreeNode *> s;

    while (root != nullptr || !s.empty())
    {
        while (root != nullptr)
        {
            k--;
            s.push(root);
            if (k == 0)
            {
                cout << s.top()->val;
                return;
            }
            root = root->left;
        }
        root = s.top();
        s.pop();
        root = root->right;
    }
}

int main(int argc, char const *argv[])
{
    MyTree tree({1, 2, 3, 4, 5, 6});
    tree.Print();
    DisplayKTree(tree.root, 6);
    return 0;
}
