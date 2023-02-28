#include "./搜索二叉树/SearchTree.h"
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 非递归法中序遍历找第一个>=k的节点
/**
 * @brief 找树第一个>=k节点的指针
 *
 * @param root 树的根节点
 * @param k
 * @param buff 储存节点值大于k的节点
 * @return void
 */
void findNode(TreeNode *root, int k, vector<TreeNode *> &buff)
{
    stack<TreeNode *> st;
    while (root != nullptr || !st.empty())
    {
        while (root != nullptr)
        {
            st.push(root);
            root = root->_left;
        }
        root = st.top();
        st.pop();
        if (root->_val > k)
        {
            buff.push_back(root);
        }
        // cout << root->_val << " ";
        root = root->_right;
    }
}

void PrintKMore(TreeNode *root, int k)
{
    vector<TreeNode *> buff;
    findNode(root, k, buff);
    std::reverse(buff.begin(), buff.end());
    for (auto &ptr : buff)
    {
        std::cout << ptr->_val << " ";
    }
    std::cout << "\n";
}

int main(int argc, char const *argv[])
{
    SearchTree tree({1, 3, 6, 2, 4, 7, 8, 9});
    PrintKMore(tree.root, 5);
    return 0;
}
