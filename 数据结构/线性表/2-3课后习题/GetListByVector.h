//为了做题，这里写一个根据传入的数组获取链表的类

//无头单链表
#include <iostream>
#include <vector>
#include <assert.h>

struct Node
{
    int _val = 0;
    Node *_next = nullptr;

    Node(int val) : _val(val) {}
};

class NodeListNoHead
{
    friend class NodeListHead;

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
    static Node *delNode(Node *&node, int val)
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

    static void _DestroyNode(Node *node)
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
            std::cout << node->_val << "-> ";
            node = node->_next;
        }
        std::cout << "null " << std::endl;
    }

    static void PrintList(Node *node)
    {
        while (node != nullptr)
        {
            std::cout << node->_val << "-> ";
            node = node->_next;
        }
        std::cout << "null " << std::endl;
    }
    Node *_head = nullptr;
};

//获取一个带头的单链表
class NodeListHead
{
public:
    NodeListHead(const std::vector<int> &vet)
    {
        assert(vet.size() > 0);
        //头
        head = new Node(-1);
        Node *node = head;
        for (int i = 0; i < vet.size(); i++)
        {
            Node *new_node = new Node(vet[i]);
            node->_next = new_node;
            node = new_node;
        }
    }
    ~NodeListHead()
    {
        NodeListNoHead::_DestroyNode(head);
    }

    void PrintList()
    {
        Node *node = head;
        while (node != nullptr)
        {
            if (node == head)
            {
                std::cout << "头-> ";
            }
            else
            {
                std::cout << node->_val << "-> ";
            }
            node = node->_next;
        }
        std::cout << "null " << std::endl;
    }

    static void PrintList(Node *node)
    {
        std::cout << "头-> ";
        node = node->_next;
        while (node != nullptr)
        {
            std::cout << node->_val << "-> ";
            node = node->_next;
        }
        std::cout << "null " << std::endl;
    }

    Node *head;
};

//带头双向循环链表
struct CircleNode
{
    CircleNode *next = nullptr;
    CircleNode *prev = nullptr;
    int data;
    CircleNode(int d) : data(d) {}
};

//不带头单向循环链表
struct SingleNode
{
    SingleNode *next = nullptr;
    int data;
    SingleNode(int d) : data(d) {}
};

class NodeListCircleSingle
{
public:
    SingleNode *head = nullptr;
    NodeListCircleSingle(const std::vector<int> &vet)
    {
        SingleNode *tail = nullptr;
        for (int i = 0; i < vet.size(); i++)
        {
            if (head == nullptr)
            {
                head = new SingleNode(vet[i]);
                tail = head;
            }
            else
            {
                tail->next = new SingleNode(vet[i]);
                tail = tail->next;
            }
        }
        tail->next = head;
    }
    void PrintList()
    {
        SingleNode *node = head;
        assert(head != nullptr);
        while (node->next != head)
        {
            std::cout << node->data << " ";
            node = node->next;
        }
        std::cout << node->data << std::endl;
    }
    ~NodeListCircleSingle()
    {
        if (head != nullptr)
        {
            SingleNode *node = head->next;
            while (node != head)
            {
                SingleNode *next = node->next;
                delete node;
                node = next;
            }
            delete head;
        }
    }
};

class NodeListHeadCircle
{
public:
    CircleNode *head;
    NodeListHeadCircle(const std::vector<int> vet)
    {
        head = new CircleNode(-1); //头节点
        CircleNode *node = head;
        for (int i = 0; i < vet.size(); i++)
        {
            CircleNode *new_node = new CircleNode(vet[i]);
            node->next = new_node;
            new_node->prev = node;
            new_node->next = head;
            head->prev = new_node;
            node = new_node;
        }
    }

    ~NodeListHeadCircle()
    {
        CircleNode *node = head->next;
        while (node != head)
        {
            CircleNode *next = node->next;
            delete node;
            node = next;
        }
        delete head;
    }

    void PrintList()
    {
        CircleNode *node = head->next;
        std::cout << "头 ";
        if (node == head)
        {
            std::cout << "empty ";
            return;
        }
        while (node != head)
        {
            std::cout << node->data << " ";
            node = node->next;
        }
        std::cout << "头 " << std::endl;
    }

    void PrintListReserve()
    {
        CircleNode *node = head->prev;
        std::cout << "头 ";
        while (node != head)
        {
            std::cout << node->data << " ";
            node = node->prev;
        }
        std::cout << "头 " << std::endl;
    }
};
