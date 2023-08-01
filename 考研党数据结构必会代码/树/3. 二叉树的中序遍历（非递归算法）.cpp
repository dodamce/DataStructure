#include "../debug.hpp" //创建二叉树方法
#include <stack>
using namespace std;

void InorderDisplay(TreeNode *root)
{
    stack<TreeNode *> st;
    while (!st.empty() || root != nullptr)
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }

        root = st.top();
        st.pop();
        cout << root->val << " ";
        root = root->right;
    }
}

int main(int argc, char const *argv[])
{
    BTree tree({2, 4, 1, 5, 6});
    tree.PrintTree();
    InorderDisplay(tree.root);
    return 0;
}