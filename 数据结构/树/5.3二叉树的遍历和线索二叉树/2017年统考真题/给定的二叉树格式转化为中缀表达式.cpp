//给了表达式树表达式
//后序遍历就是表达式的后缀表达式
//前序遍历就是表达式的前缀表达式
//中序遍历就是表达式的中缀表达式

#include "GetTreeByVector.h" //树结构的定义，采用层序构建，传入层序结果构建完全二叉树，写的比较搓，将就着用

#include <string>

using namespace std;

//特别的，如果在中序遍历时在特定位置需要加括号
//(a+b)*(c*d)
//在中序遍历时如果不是叶子节点或者运算符节点不需要加括号，其他节点在遍历左子树前+(遍历完右子树后+)

void DisplayTree(TreeNode<char> *root, string &buff)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left != nullptr)
        buff.push_back('(');
    DisplayTree(root->left, buff);
    buff.push_back(root->val);
    DisplayTree(root->right, buff);
    if (root->right != nullptr)
        buff.push_back(')');
}

string DisplayTree(TreeNode<char> *root)
{
    string ret;
    DisplayTree(root, ret);
    //多了一个大括号
    return ret.substr(1, ret.size() - 2);
}

int main()
{
    MyTree<char> tree({'*', '+', '*', 'a', 'b', 'c', 'd'});
    tree.Print();
    cout << DisplayTree(tree.root);
}