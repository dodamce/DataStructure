//先获取叶子节点，在使用叶子节点的右指针链接成单链表

#include "GetTreeByVector.h"

#include <queue>
#include <assert.h>

using namespace std;

TreeNode *TurnLeaveToList(TreeNode *root)
{

    //层序遍历，获取叶子节点
    queue<TreeNode *> leave;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        // cout << "INFO:" << node->val << endl;
        if (node->left == nullptr && node->right == nullptr)
        {
            leave.push(node);
        }
        if (node->left != nullptr)
        {
            q.push(node->left);
        }
        if (node->right != nullptr)
        {
            q.push(node->right);
        }
    }

    //将叶子节点合并成链表,不带头,这里创建新节点返回链表，因为自己实现的树，直接在树上修改指向会倒是析构函数崩溃
    TreeNode *head = nullptr;
    TreeNode *tail = nullptr;
    while (!leave.empty())
    {
        TreeNode *node = leave.front();
        leave.pop();
        if (head == nullptr)
        {
            head = new TreeNode(node->val);
            tail = head;
            head->right = nullptr;
        }
        else
        {
            tail->right = new TreeNode(node->val);
            tail = tail->right;
        }
    }
    tail->right = nullptr;
    return head;
}

int main(int argc, char const *argv[])
{
    MyTree tree({1, 2, 3, 4, 5, 6});
    tree.Print();
    TreeNode *node = TurnLeaveToList(tree.root);
    //边打印边析构，懒得单独写链表析构了
    while (node != nullptr)
    {
        cout << node->val << " ";
        TreeNode *next = node->right;
        delete node;
        node = next;
    }
    cout << "\n";
    return 0;
}
