// 二叉搜索树头文件实现
#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode
{
    int _val;
    TreeNode *_left;
    TreeNode *_right;
    TreeNode(int val) : _val(val), _left(nullptr), _right(nullptr) {}
};

class SearchTree
{
public:
    TreeNode *root = nullptr;

private:
    /**
     * @brief 在二叉搜索树中查找节点值为val的节点
     *
     * @param val 查找节点的值
     * @param node 如果找到了这个节点，node就是这个节点的地址，否则为null
     * @param part part这个节点的父亲，如果这个节点为null,这个参数输出null
     */
    void _find(int val, TreeNode *&node, TreeNode *&part)
    {
        TreeNode *ptr = root;
        TreeNode *prev = nullptr;
        while (ptr != nullptr)
        {
            if (ptr->_val == val)
            {
                node = ptr;
                break;
            }
            else if (ptr->_val > val)
            {
                prev = ptr;
                ptr = ptr->_left;
            }
            else
            {
                prev = ptr;
                ptr = ptr->_right;
            }
        }
        node = ptr;
        part = prev;
    }

    bool _erase(int val, TreeNode *&node)
    {
        if (node == nullptr)
        {
            return false;
        }
        else
        {
            if (node->_val > val)
            {
                _erase(val, node->_left);
            }
            else if (node->_val < val)
            {
                _erase(val, node->_right);
            }
            else
            {

                if (node->_left == nullptr)
                {
                    TreeNode *del = node;
                    node = node->_right;
                    delete del;
                }
                else if (node->_right == nullptr)
                {
                    TreeNode *del = node;
                    node = node->_left;
                    delete del;
                }
                else
                {
                    // 找要删除节点的后继
                    TreeNode *right_min_node = node->_right;
                    while (right_min_node->_left != nullptr)
                    {
                        right_min_node = right_min_node->_left;
                    }

                    // 记录right_min_node这个节点的值，吧这个节点的值和node节点交换，在删除right_min_node这个节点即可
                    // right_min_node这个节点的左子树一定为空，在上面顶点流程会处理
                    int tmp = right_min_node->_val;
                    _erase(tmp, node->_right);
                    node->_val = tmp;
                }
            }
            return true;
        }
    }

    // 判断一棵树是否是二叉搜索树,检查每个节点是否满足节点值的取值范围
    bool _isSearchTree(TreeNode *node, int min, int max)
    {
        if (node == nullptr)
            return true;

        if (node->_val < min || node->_val > max)
        {
            return false;
        }
        return _isSearchTree(node->_left, min, node->_val - 1) && _isSearchTree(node->_right, node->_val + 1, max);
    }

    void _display_inorder(TreeNode *node)
    {
        if (node == nullptr)
            return;
        _display_inorder(node->_left);
        std::cout << node->_val << " ";
        _display_inorder(node->_right);
    }

    int _max()
    {
        TreeNode *node = root;
        while (node->_right != nullptr)
        {
            node = node->_right;
        }
        return node->_val;
    }

    int _min()
    {
        TreeNode *node = root;
        while (node->_left != nullptr)
        {
            node = node->_left;
        }
        return node->_val;
    }

public:
    SearchTree() = default;
    SearchTree(const std::vector<int> &buff)
    {
        for (int i = 0; i < buff.size(); i++)
        {
            insert(buff[i]);
        }
    }
    // 不允许重复插入相同的值
    bool insert(int val)
    {
        if (root == nullptr)
        {
            root = new TreeNode(val);
            return true;
        }
        else
        {
            TreeNode *pos = nullptr;
            TreeNode *prev = nullptr;
            _find(val, pos, prev);
            if (pos != nullptr)
            {
                // 之前插入过，值重复
                return false;
            }
            else
            {
                // pos==nullptr;
                if (prev->_val > val)
                {
                    prev->_left = new TreeNode(val);
                }
                else
                {
                    prev->_right = new TreeNode(val);
                }
                return true;
            }
        }
    }

    // 查找节点值为val的节点
    bool find(int val)
    {
        TreeNode *node;
        TreeNode *part;
        _find(val, node, part);
        return node != nullptr;
    }

    // 删除搜索二叉树节点
    bool erase(int val)
    {
        return _erase(val, root);
    }

    // 判断这颗树是否为二叉搜索树
    bool isSearchTree()
    {
        return _isSearchTree(root, _min(), _max());
    }

    // 中序遍历二叉搜索树
    void inorder()
    {
        _display_inorder(root);
        std::cout << "\n";
    }
};