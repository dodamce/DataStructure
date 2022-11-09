#include <vector>
#include <iostream>

struct TreeNode
{
    int data;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    int ltag = 0;
    int rtag = 0;
    TreeNode(int _data) : data(_data) {}
};

class Tree
{
private:
    void InsertNode(int data)
    {
        if (root == nullptr)
        {
            root = new TreeNode(data);
        }
        else
        {
            TreeNode *prev = nullptr;
            TreeNode *node = root;
            while (node != nullptr)
            {
                prev = node;
                if (node->data >= data)
                {
                    node = node->left;
                }
                else
                {
                    node = node->right;
                }
            }
            TreeNode *next = new TreeNode(data);
            if (prev->data >= data)
            {
                prev->left = next;
            }
            else
            {
                prev->right = next;
            }
        }
    }

    void _InodesDisplay(TreeNode *root)
    {
        if (root == nullptr)
            return;
        _InodesDisplay(root->left);
        std::cout << root->data << " ";
        _InodesDisplay(root->right);
    }

    void Destroy(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        Destroy(root->left);
        Destroy(root->right);
        delete root;
    }

public:
    TreeNode *root;

    Tree(const std::vector<int> &vet)
    {
        this->root = nullptr;
        for (int i = 0; i < vet.size(); i++)
        {
            InsertNode(vet[i]);
        }
    }

    ~Tree()
    {
        Destroy(root);
    }

    //中序遍历
    void InodesDisplay()
    {
        _InodesDisplay(root);
        std::cout << "\n";
    }
};
