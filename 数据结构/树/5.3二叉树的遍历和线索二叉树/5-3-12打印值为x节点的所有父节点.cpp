#include "GetTreeByVector.h"
#include <stack>

using namespace std;

void Print(stack<TreeNode *> st)
{
    while (!st.empty())
    {
        cout << st.top()->val << " ";
        st.pop();
    }
}

//后序遍历，将结果保存到栈上，节点值为x的节点后（只有一个），栈元素就是这个节点的所有父节点
void DisPlay(TreeNode *root, int target)
{
    TreeNode *prev = nullptr;
    stack<TreeNode *> st;
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
            //判断此时的节点是否和值相同
            if (root->val == target)
            {
                //打印栈的值
                Print(st);
            }
            prev = root;
            root = nullptr;
        }
        else
        {
            st.push(root);
            root = root->right;
        }
    }
}

int main(int argc, char const *argv[])
{
    MyTree tree({1, 2, 3, 4, 5, 6, 7});
    tree.Print();
    DisPlay(tree.root, 5);
    return 0;
}
