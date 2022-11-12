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

/**
思路：
1. 这个节点node如果有右孩子，说明这个节点就是这个节点的后序遍历前驱节点（左->右->根）
2. 这个节点如果只有左孩子，说明左孩子是这个节点的前序节点
3. 这个节点是中序遍历的第一个节点，这个节点的前序节点不存在
4. 这个节点如果没有左孩子和右孩子，说明是线索化的节点，要向上找
    这个节点的左线索指向某个祖先节点parent，如果node有左孩子，前驱就是这个左孩子
    如果这个节点无左孩子，向上找其有左孩子父节点，这个父节点的左孩子就是后序遍历的前驱
 */

/**
 * @brief 返回list中序线索化二叉树后序遍历 target的前驱节点
 *
 * @param list list中序线索化二叉树
 * @param target
 * @return TreeNode*返回前序节点指针
 */
TreeNode *InPostPre(TreeNode *list, TreeNode *target)
{
    TreeNode *ret = nullptr;
    if (target->rtag == 0)
    {
        ret = target->right;
    }
    else if (target->ltag == 0)
    {
        // rtag==1无右孩子，只右左孩子
        ret = target->left;
    }
    //线索化节点
    else if (target->left == nullptr)
    {
        //中序遍历第一个节点，在后序遍历中也是第一个没有前驱
        ret = nullptr;
    }
    else
    {
        //不是特殊的线索节点，向上找，从中序前驱线索，找某个祖先节点parent
        while (target->ltag == 1 && target->left != nullptr)
        {
            target = target->left;
        }
        if (target->ltag == 0)
        {
            ret = target->left;
        }
        else
        {
            ret = nullptr; //单支树，target是叶子节点
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    Tree tree({5, 3, 6, 2, 1, 7});
    tree.InodesDisplay();
    TreeNode *root = InorderSpan(tree.root); //获取中序线索化二叉树
    DisplayTree(root);
    cout << "\n";
    cout << InPostPre(root, root)->data;
    Destroy(root);
    return 0;
}
