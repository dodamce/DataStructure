#include "GetListByVector.h"

using namespace std;

//递归删除单链表值为val的元素
Node *delNode(Node *node, int val)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    Node *next = delNode(node->_next, val);
    node->_next = next;
    
    if (node->_val == val)
    {
        Node *next = node->_next;
        delete node;
        return next;
    }
    return node;
}

int main()
{
    NodeListNoHead list({1, 1, 2, 1, 1, 4, 4, 1, 1});
    list.PrintList();
    list._head = delNode(list._head, 1);
    list.PrintList();
    return 0;
}