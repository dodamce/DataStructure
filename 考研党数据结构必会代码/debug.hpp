#include <vector>
#include <iostream>
using namespace std;

void PrintVector(const vector<int> &vet)
{
    for (auto &val : vet)
    {
        cout << val << " ";
    }
    cout << endl;
}

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

// 更好的二叉树打印(考研不需要掌握,为了打印树更直观),打印思路:https://blog.csdn.net/dodamce/article/details/130925799?spm=1001.2014.3001.5501
struct PrintCur
{
    int deep(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = deep(root->left);
        int right = deep(root->right);
        return max(left, right) + 1;
    }

    void dfs(TreeNode *root, vector<vector<string>> &ret, int row, int col, const int &deep)
    {
        if (root == nullptr)
        {
            return;
        }
        ret[row][col] = to_string(root->val);
        if (root->left != nullptr)
            dfs(root->left, ret, row + 1, col - (1 << (deep - row - 1)), deep);
        if (root->right != nullptr)
            dfs(root->right, ret, row + 1, col + (1 << (deep - row - 1)), deep);
    }

    void printTree(TreeNode *root)
    {
        int tree_deep = deep(root) - 1; // 根节点高度为0
        int row = tree_deep + 1;
        int col = (1 << row) - 1;
        vector<vector<string>> ret(row, vector<string>(col, ""));
        dfs(root, ret, 0, (col - 1) / 2, tree_deep);
        for (int i = 0; i < ret.size(); i++)
        {
            for (int j = 0; j < ret[i].size(); j++)
            {
                cout << ret[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class BTree
{
    // 递归创建树
    TreeNode *CreateTree(const vector<int> &vet, int pos)
    {
        TreeNode *node = nullptr;
        if (pos >= vet.size())
        {
            return nullptr;
        }
        node = new TreeNode(vet[pos]);
        node->left = CreateTree(vet, pos * 2 + 1);
        node->right = CreateTree(vet, pos * 2 + 2);
        return node;
    }

    // 非递归创建树,重载
    TreeNode *CreateTree(const vector<int> &vet)
    {
        vector<TreeNode *> nodes;
        // 先创建节点，将节点保存起来，最后修改指针即可
        for (int i = 0; i < vet.size(); i++)
        {
            nodes.push_back(new TreeNode(vet[i]));
        }

        // 修改节点指针的指向
        for (int i = 0; i < nodes.size(); i++)
        {
            if (2 * i + 1 < nodes.size())
                nodes[i]->left = nodes[2 * i + 1];
            if (2 * i + 2 < nodes.size())
                nodes[i]->right = nodes[2 * i + 2];
        }
        return nodes.front();
    }

public:
    PrintCur print;
    TreeNode *root;
    BTree(const vector<int> &vet)
    {
        // root = CreateTree(vet, 0);
        root = CreateTree(vet);
    }

    void PrintTree()
    {
        print.printTree(root);
    }
};