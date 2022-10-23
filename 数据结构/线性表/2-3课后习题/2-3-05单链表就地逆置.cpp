#include "GetListByVector.h"

//原地逆置带头单链表
void reserve(Node *node, Node *&head)
{
    if (nullptr == node->_next)
    {
        //记录转换后的第一个有效节点
        head->_next = node;
        return;
    }
    reserve(node->_next, head);
    node->_next->_next = node;
    //逆转后将这个节点的后置节点置空
    node->_next = nullptr;
}

int main()
{
    NodeListHead list({1, 2, 3, 4, 5, 6, 7, 8, 9});
    reserve(list.head->_next, list.head);
    list.PrintList();
    return 0;
}