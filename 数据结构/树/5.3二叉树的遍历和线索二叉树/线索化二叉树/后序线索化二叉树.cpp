#include "CreatTree.h"

#include <stack>

using namespace std;

//后序线索二叉树
void PostorderSpan(TreeNode *root, TreeNode *&prev)
{
    if (root == nullptr)
        return;
    PostorderSpan(root->left, prev);
    PostorderSpan(root->right, prev);

    if (root->left == nullptr)
    {
        root->left = prev;
        root->ltag = 1;
    }
    if (prev != nullptr && prev->right == nullptr)
    {
        prev->rtag = 1;
        prev->right = root;
    }
    prev = root;
}

TreeNode *PostorderSpan(TreeNode *&root)
{
    TreeNode *ret = root;
    root = nullptr;
    TreeNode *prev = nullptr;
    PostorderSpan(ret, prev);
    return ret;
}

//遍历线索二叉树
//先按照 根节点->右孩子->左孩子 的方式来遍历访问节点，并且将顺序记录一下，最后将刚才记录的顺序翻转即可(使用栈)
TreeNode *GetNextNode(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;

    //将前驱节点返回，最后逆置相当于找后继节点
    if (root->ltag == 1)
    {
        return root->left;
    }
    else
    {
        // root->ltag = 0;有左子树
        if (root->rtag == 1)
        {
            //存在后继节点
            return root->left;
        }
        else if (root->right != nullptr && root->rtag == 0)
        {
            //左右子树都存在，向右子树走
            return root->right;
        }
        else
        {
            return root->left;
        }
    }
}

void DisplayTree(TreeNode *root)
{
    stack<TreeNode *> st;
    while (root != nullptr)
    {
        st.push(root);
        root = GetNextNode(root);
    }

    while (!st.empty())
    {
        cout << st.top()->data << " ";
        st.pop();
    }
}

int main(int argc, char const *argv[])
{
    Tree tree({5, 1, 0, 2});
    tree.InodesDisplay();
    TreeNode *node = PostorderSpan(tree.root);
    DisplayTree(node);
    return 0;
}
