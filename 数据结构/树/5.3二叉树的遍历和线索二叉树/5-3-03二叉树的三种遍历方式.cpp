#include "GetTreeByVector.h"
#include <stack>
#include <assert.h>
using namespace std;

//前序遍历递归
void PreDisplay(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << " ";
    PreDisplay(root->left);
    PreDisplay(root->right);
}
//前序遍历非递归
void PreDisplayUsStack(TreeNode *root)
{
    assert(root != nullptr);
    stack<TreeNode *> st;
    while (root != nullptr || !st.empty())
    {
        while (root != nullptr)
        {
            cout << root->val << " ";
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        root = root->right;
    }
    cout << "\n";
}

//中序遍历递归
void InodesDisplay(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    InodesDisplay(root->left);
    cout << root->val << " ";
    InodesDisplay(root->right);
}

//中序遍历非递归
void InodesDisplayUsStack(TreeNode *root)
{
    assert(root != nullptr);
    stack<TreeNode *> st;
    while (root != nullptr || !st.empty())
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        cout << root->val << " ";
        st.pop();
        root = root->right;
    }
}

//后续遍历递归
void PostorderDisplay(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    PostorderDisplay(root->left);
    PostorderDisplay(root->right);
    cout << root->val << " ";
}

//后续遍历非递归
//从栈中弹出的节点，我们只能确定其左子树肯定访问完了，但是无法确定右子树是否访问过。
// 因此，我们在后序遍历中，引入了一个prev来记录历史访问记录。
void PostorderDisplayUsStack(TreeNode *root)
{
    assert(root != nullptr);
    stack<TreeNode *> st;
    TreeNode *prev = nullptr;
    while (root != nullptr || !st.empty())
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if (root->right == nullptr || root->right == prev)
        {
            cout << root->val << " ";
            prev = root;
            root = nullptr;
        }
        else
        {
            //右子树没有遍历完
            st.push(root);
            root = root->right;
        }
    }
}

int main()
{
    MyTree tree({1, 2, 3, 4, 5});
    tree.Print();
    // PreDisplay(tree.root);
    // PreDisplayUsStack(tree.root);
    // InodesDisplay(tree.root);
    // InodesDisplayUsStack(tree.root);
    // PostorderDisplay(tree.root);
    PostorderDisplayUsStack(tree.root);

    return 0;
}