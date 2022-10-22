//为了做题，这里写一个根据传入的数组获取链表的类

//无头单链表
#include <iostream>
#include <vector>

struct Node
{
    int _val = 0;
    Node *_next = nullptr;

    Node(int val) : _val(val) {}
};

class NodeListNoHead
{
public:
    NodeListNoHead(const std::vector<int> &vet)
    {
        Node *tail = nullptr;
        for (int i = 0; i < vet.size(); i++)
        {
            if (_head == nullptr)
            {
                _head = new Node(vet[i]);
                tail = _head;
            }
            else
            {
                tail->_next = new Node(vet[i]);
                tail = tail->_next;
            }
        }
    }

    //递归删除链表节点
    Node *delNode(Node *&node, int val)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->_val == val)
        {
            Node *next = node->_next;
            delete node;
            return next;
        }
        Node *next = delNode(node->_next, val);
        node->_next = next;
        return node;
    }

private:
    void _DestroyNode(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        _DestroyNode(node->_next);
        delete node;
    }

public:
    ~NodeListNoHead()
    {
        _DestroyNode(_head);
    }

    void PrintList()
    {
        Node *node = _head;
        while (node != nullptr)
        {
            std::cout << node->_val << " ";
            node = node->_next;
        }
        std::cout << std::endl;
    }
    Node *_head = nullptr;
};
