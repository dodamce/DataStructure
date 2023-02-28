#include <iostream>

#include <vector>

// order阶B树，节点最多order-1个元素，但是需要开辟order大小的空间,因为我是先插入后在判断扩容的
template <class ValueType, size_t order>
struct TreeNode
{
    std::vector<ValueType> _value;                   // 存放节点值
    std::vector<TreeNode<ValueType, order> *> _subs; // 存放节点的子树,空间大小为order+1
    TreeNode<ValueType, order> *_parent;             // 父指针
    size_t _size;                                    // 记录实际存储关键字个数

    TreeNode()
    {
        _value.resize(order);
        _subs.resize(order + 1);
        for (size_t i = 0; i < order; i++)
        {
            _value[i] = ValueType();
            _subs[i] = nullptr;
        }
        _subs[order] = nullptr;
        _parent = nullptr;
        _size = 0;
    }
};

template <class ValueType, size_t order>
class BTree
{
    typedef TreeNode<ValueType, order> TreeNode;

private:
    TreeNode *_root = nullptr;

public:
    BTree(const std::vector<ValueType> &vet)
    {
        for (auto &val : vet)
        {
            insert(val);
        }
    }
    BTree() = default;
    bool insert(const ValueType &value)
    {
        if (_root == nullptr)
        {
            _root = new TreeNode;
            _root->_value[0] = value;
            _root->_size += 1;
            return true;
        }
        else
        {
            // 找要插入的位置
            std::pair<TreeNode *, int> ret = _findPos(value);

            if (ret.second >= 0)
            {
                // 不允许冗余
                return false;
            }

            TreeNode *cur = ret.first; // 要插入的节点
            int insert_value = value;
            TreeNode *child = nullptr;
            while (true)
            {
                _insert(cur, insert_value, child);
                if (cur->_size == order)
                {
                    // 节点放满了需要分裂
                    int mid = order / 2;
                    TreeNode *node = new TreeNode; // node存放[mid+1,order-1]的数据
                    size_t pos = 0;
                    for (size_t i = mid + 1; i < order; i++)
                    {
                        node->_value[pos] = cur->_value[i];
                        node->_subs[pos] = cur->_subs[i];
                        // 更新父节点
                        if (cur->_subs[i] != nullptr)
                        {
                            cur->_subs[i]->_parent = node;
                        }
                        pos += 1;
                        // 将cur移出的位置清空
                        cur->_value[i] = ValueType();
                        cur->_subs[i] = nullptr;
                    }
                    // node节点中，新插入的值的孩子节点指针没处理
                    node->_subs[order] = cur->_subs[order];
                    if (cur->_subs[order] != nullptr)
                    {
                        // 更新父节点
                        cur->_subs[order]->_parent = node;
                    }
                    cur->_subs[order] = nullptr;
                    node->_size = pos;
                    cur->_size -= pos + 1; // cur还提取了一个值作为这两个节点父亲,下面的代码会操作

                    ValueType midValue = cur->_value[mid];
                    cur->_value[mid] = ValueType();

                    if (cur->_parent == nullptr)
                    {
                        // 新创建父节点，这个节点是cur和node的父亲
                        _root = new TreeNode;
                        _root->_value[0] = midValue;
                        _root->_subs[0] = cur;
                        _root->_subs[1] = node;
                        _root->_size = 1;
                        cur->_parent = _root;
                        node->_parent = _root;
                        break;
                    }
                    // 转划为向cur->_parent这个位置插入midValue问题，可以通过while循环解决
                    insert_value = midValue;
                    child = node;
                    cur = cur->_parent;
                }
                else
                {
                    // 节点没有插满，插入结束
                    return true;
                }
            }
        }
        return true;
    }

    // 删除指定元素
    void erase(const ValueType &value)
    {
        std::pair<TreeNode *, int> ret = _findPos(value);

        if (ret.second == -1)
        {
            // 没有找到删除的元素
            return;
        }
        else
        {
            TreeNode *del = ret.first;
            if (!_isLeave(del))
            {
                // 如果删除的节点不是终端节点，转化为终端节点后在删除
                TreeNode *prev = del->_subs[ret.second]; // 找直接前继节点(左子树的最右节点)
                while (prev->_subs[ret.second + 1] != nullptr)
                {
                    prev = prev->_subs[ret.second + 1];
                }
                // 交换节点，转化为删除终端节点
                ValueType delValue = del->_value[ret.second];
                del->_value[ret.second] = prev->_value[prev->_size - 1];
                prev->_value[prev->_size - 1] = delValue;
                erase(delValue);
            }
            else
            {
                // 是终端节点，找其兄弟节点
                /**
                 * @brief 考研对B树的代码不怎么考核，而删除的代码比较复杂，需要找这要删除这个节点的兄弟节点
                 *        出于时间考虑，这里先空开。
                 *        我认为删除节点操作需要找到删除节点的B树节点指针才行，这样才能准确的找到删除节点的兄弟B树节点的位置
                 */
            }
        }
    }

    void disPlayInorder()
    {
        _disPlay(_root);
    }

private:
    bool _isLeave(TreeNode *node)
    {
        bool ret = true;
        for (int i = 0; i < node->_size; i++)
        {
            if (node->_subs[i] != nullptr)
            {
                ret = false;
                break;
            }
        }
        return ret && node->_subs[node->_size] == nullptr;
    }

    void _disPlay(TreeNode *node)
    {
        if (node == nullptr)
            return;

        for (size_t i = 0; i < node->_size; i++)
        {
            _disPlay(node->_subs[i]);
            std::cout << node->_value[i] << " ";
        }
        // 最后剩余右子树
        _disPlay(node->_subs[node->_size]);
    }

    void _insert(TreeNode *node, int value, TreeNode *child)
    {
        // 在数组中找value插入的位置，需要移动数组
        int endPos = node->_size - 1;
        while (endPos >= 0)
        {
            if (value < node->_value[endPos])
            {
                // 挪动数据
                node->_value[endPos + 1] = node->_value[endPos];
                node->_subs[endPos + 2] = node->_subs[endPos + 1];
                endPos -= 1;
            }
            else
            {
                break;
            }
        }

        // endPos位置是第一个值小于value的位置,value要插入到其后边
        node->_value[endPos + 1] = value;
        node->_subs[endPos + 2] = child;
        if (child != nullptr)
        {
            child->_parent = node;
        }
        node->_size += 1;
    }
    // 查找要插入的叶子节点以及数组下标
    std::pair<TreeNode *, int> _findPos(const ValueType &value)
    {
        TreeNode *par = nullptr;
        TreeNode *cur = _root;
        while (cur != nullptr)
        {
            int pos = 0; // 先从数组下标为0处开始
            while (pos < cur->_size)
            {
                if (value < cur->_value[pos])
                {
                    //_value[pos]左子树
                    break;
                }
                else if (value > cur->_value[pos])
                {
                    pos += 1;
                }
                else
                {
                    return std::make_pair(cur, pos);
                }
            }
            par = cur;
            cur = cur->_subs[pos];
        }
        return std::make_pair(par, -1);
    }
};