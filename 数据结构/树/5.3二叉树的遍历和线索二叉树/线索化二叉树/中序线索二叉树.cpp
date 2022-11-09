//思路:https://blog.csdn.net/songshuai0223/article/details/106551499?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166795700016782425681940%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166795700016782425681940&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-106551499-null-null.142^v63^control,201^v3^control_2,213^v2^t3_esquery_v1&utm_term=%E7%BA%BF%E7%B4%A2%E4%BA%8C%E5%8F%89%E6%A0%91&spm=1018.2226.3001.4187

#include "CreatTree.h"

using namespace std;

//中序线索化二叉树
void InorderSpan(TreeNode *root, TreeNode *&prev)
{
    if (root == nullptr)
        return;

    InorderSpan(root->left, prev);

    //当前节点左指针为空，左指针指向前驱
    if (root->left == nullptr)
    {
        root->left = prev;
        root->ltag = 1;
    }
    // prev节点右指针为空，右指针指向当前节点(后继节点)
    if (prev != nullptr && prev->right == nullptr)
    {
        prev->right = root;
        prev->rtag = 1;
    }
    prev = root;

    InorderSpan(root->right, prev);
}

TreeNode *InorderSpan(TreeNode *&root)
{
    TreeNode *ret = root;
    root = nullptr; //摘头，Tree类防止析构函数崩溃
    TreeNode *prev = nullptr;
    InorderSpan(ret, prev);
    return ret;
}

//中序线索化二叉树的遍历

TreeNode *GetNextNode(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    // 右标志位 1，可以直接得到后继节点
    if (root->rtag == 1)
    {
        return root->right;
    }
    // 右标志位0，则要找到右子树最左下角的节点
    else
    {
        TreeNode *ret = root->right;
        while (ret != nullptr && ret->ltag == 0)
        {
            ret = ret->left;
        }
        return ret;
    }
}
void DisplayTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    //找最左下的节点
    while (root->ltag == 0)
    {
        root = root->left;
    }
    cout << root->data << " ";
    //根据后继节点打印这颗树
    while (root->right != nullptr)
    {
        root = GetNextNode(root);
        cout << root->data << " ";
    }
}

//释放线索化二叉树的节点
void Destroy(TreeNode *root)
{
    if (root == nullptr)
        return;
    while (root->ltag == 0)
    {
        root = root->left;
    }
    TreeNode *next = root->right;
    delete root;
    root = nullptr;
    while (next != nullptr)
    {
        TreeNode *node = next;
        next = GetNextNode(next);
        delete node;
        node = nullptr;
    }
}

int main(int argc, char const *argv[])
{
    Tree tree({3, 2, 4, 6, 7, 1, 2, 7, 1, 0, 7, 9});
    tree.InodesDisplay();

    TreeNode *ret = InorderSpan(tree.root);
    DisplayTree(ret);
    //销毁线索化二叉树
    Destroy(ret);
    return 0;
}

