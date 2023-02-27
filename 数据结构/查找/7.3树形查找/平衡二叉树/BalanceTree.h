#include <iostream>
#include <vector>
#include <algorithm>

struct Node
{
    int _bf;
    Node *_left;
    Node *_right;
    Node *_parent;

    int _val;
    Node(int val) : _bf(0), _left(nullptr), _right(nullptr), _parent(nullptr), _val(val) {}
};

class BalanceTree
{
public:
    Node *root;

public:
    ~BalanceTree() {}

    void InorderDisplay()
    {
        _DisPlay(root);
        std::cout << "\n";
    }
    BalanceTree(const std::vector<int> buff)
    {
        for (auto &num : buff)
        {
            insert(num);
        }
    }
    bool insert(int val)
    {
        // 不允许值重复
        if (root == nullptr)
        {
            root = new Node(val);
            return true;
        }
        else
        {
            Node *prev = nullptr;
            Node *cur = root;
            while (cur != nullptr)
            {
                prev = cur;
                if (cur->_val < val)
                {
                    cur = cur->_right;
                }
                else if (cur->_val > val)
                {
                    cur = cur->_left;
                }
                else
                {
                    // 数据冗余
                    return false;
                }
            }
            // cur==nullptr
            cur = new Node(val);

            if (prev->_val > val)
                prev->_left = cur;
            else
                prev->_right = cur;

            cur->_parent = prev;

            // 更新平衡因子
            while (prev != nullptr)
            {
                // 判断插入位置
                if (prev->_left == cur)
                    prev->_bf--;
                else if (prev->_right == cur)
                    prev->_bf++;

                if (prev->_bf == 0)
                {
                    break; // 插入后仍然是AVL树
                }
                else if (prev->_bf == -1 || prev->_bf == 1)
                {
                    cur = prev;
                    prev = prev->_parent; // 这次插入影响高度，需要向上调整
                }
                else if (prev->_bf == -2 || prev->_bf == 2)
                {
                    // 不是AVL树需要调整高度
                    if (prev->_bf == -2)
                    {
                        if (cur->_bf == -1)
                        {
                            // 右单旋
                            TurnRight(prev);
                        }
                        else if (cur->_bf == 1)
                        {
                            // 左右双旋
                            TurnLeftRight(prev);
                        }
                    }
                    else if (prev->_bf == 2)
                    {
                        if (cur->_bf == -1)
                        {
                            // 右左双旋
                            TurnRightLeft(prev);
                        }
                        else if (cur->_bf == 1)
                        {
                            // 左单旋
                            TurnLeft(prev);
                        }
                    }
                }
            }
            return true;
        }
    }

    // 判断一棵树是否是AVL树
    bool isAVLTree()
    {
        return _isAVLTree(root);
    }

    void erase(int val)
    {
        _erase(val, root);
        _adjust(root);
    }

private:
    void _adjust(Node *node)
    {
        // 后续遍历调整搜索二叉树为AVL树
        if (node == nullptr)
        {
            return;
        }
        _adjust(node->_left);
        _adjust(node->_right);
        int leftHeight = _height(node->_left);
        int rightHeight = _height(node->_right);
        node->_bf = rightHeight - leftHeight;

        if (node->_bf == 2 || node->_bf == -2)
        {
            Node *left = node->_left;
            Node *right = node->_right;

            if (node->_bf == -2)
            {
                if ((left != nullptr && left->_bf == -1) || (right != nullptr && right->_bf == -1))
                {
                    // 右旋
                    TurnRight(node);
                }
                else if ((left != nullptr && left->_bf == 1) || (right != nullptr && right->_bf == 1))
                {
                    // 左右双旋
                    TurnLeftRight(node);
                }
            }
            else if (node->_bf == 2)
            {
                if ((left != nullptr && left->_bf == -1) || (right != nullptr && right->_bf == -1))
                {
                    // 右左旋
                    TurnRightLeft(node);
                }
                else if ((left != nullptr && left->_bf == 1) || (right != nullptr && right->_bf == 1))
                {
                    // 左旋
                    TurnLeft(node);
                }
            }
        }
    }
    // 搜索二叉树删除方式
    void _erase(int val, Node *&node)
    {
        // 删除节点值为val的节点，并且返回删除后这个节点的指针
        if (node == nullptr)
        {
            return;
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
                    Node *del = node;
                    node = node->_right;
                    if (node != nullptr)
                        node->_parent = del->_parent;
                    delete del;
                }
                else if (node->_right == nullptr)
                {
                    Node *del = node;
                    node = node->_left;
                    if (node != nullptr)
                        node->_parent = del->_parent;
                    delete del;
                }
                else
                {
                    // 找要删除节点的后继
                    Node *right_min_node = node->_right;
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
        }
    }
    void _DisPlay(Node *root)
    {
        if (root == nullptr)
            return;
        _DisPlay(root->_left);
        std::cout << root->_val << " ";
        _DisPlay(root->_right);
    }

    int _height(Node *node)
    {
        if (node == nullptr)
            return 0;

        int leftHeight = _height(node->_left);
        int rightHeight = _height(node->_right);
        return std::max(leftHeight, rightHeight) + 1;
    }

    bool _isAVLTree(Node *node)
    {
        if (node == nullptr)
        {
            return true;
        }
        int leftHigh = _height(node->_left);
        int rightHigh = _height(node->_right);

        if (node->_bf != rightHigh - leftHigh)
        {
            std::cout << "ERROR:BF " << node->_bf << std::endl;
            return false;
        }

        return std::abs(rightHigh - leftHigh) < 2 && _isAVLTree(node->_left) && _isAVLTree(node->_right);
    }
    /**
     * 旋转代码结合博客流程对照
     */

    // 右单旋
    void TurnRight(Node *node)
    {
        Node *left = node->_left;
        Node *right = left->_right;

        node->_left = right;
        if (right != nullptr)
        {
            right->_parent = node;
        }

        left->_right = node;
        Node *parent = node->_parent; // 原父母
        node->_parent = left;

        // 修改平衡因子
        node->_bf = 0;
        left->_bf = 0;

        if (node == root)
        {
            // 旋转根节点
            root = left;
            root->_parent = parent;
        }
        else
        {
            left->_parent = parent;
            if (parent->_left == node)
            {
                parent->_left = left;
            }
            else
            {
                parent->_right = left;
            }
        }
    }

    // 左单旋
    void TurnLeft(Node *node)
    {
        Node *right = node->_right;
        Node *left = right->_left;

        node->_right = left;
        if (left != nullptr)
        {
            left->_parent = node;
        }

        right->_left = node;
        Node *parent = node->_parent;
        node->_parent = right;

        node->_bf = 0;
        right->_bf = 0;

        if (node == root)
        {
            node = right;
            right->_parent = parent;
        }
        else
        {
            right->_parent = parent;
            if (parent->_left == node)
            {
                parent->_left = right;
            }
            else
            {
                parent->_right = right;
            }
        }
    }

    // 左右双旋
    void TurnLeftRight(Node *node)
    {
        Node *left = node->_left;
        Node *right = left->_right;

        TurnLeft(left);
        TurnRight(node);

        // 调整平衡因子
        if (right->_bf == 1)
        {
            // 新节点插入到right节点的右子树
            right->_bf = 0;
            left->_bf = -1;
            node->_bf == 0;
        }
        else if (right->_bf == -1)
        {
            // 新节点插入到right节点的左子树上
            right->_bf = 0;
            left->_bf = 0;
            node->_bf = 1;
        }
        else if (right->_bf = 0)
        {
            right->_bf = 0;
            left->_bf = 0;
            node->_bf = 0;
        }
    }

    // 右左双旋
    void TurnRightLeft(Node *node)
    {
        Node *right = node->_right;
        Node *left = right->_left;

        TurnRight(right);
        TurnLeft(node);

        if (left->_bf == 1)
        {
            left->_bf = 0;
            right->_bf = 0;
            node->_bf = -1;
        }
        else if (left->_bf == -1)
        {
            left->_bf = 0;
            right->_bf = 1;
            node->_bf = 0;
        }
        else if (left->_bf = 0)
        {
            left->_bf = 0;
            right->_bf = 0;
            node->_bf = 0;
        }
    }
};
