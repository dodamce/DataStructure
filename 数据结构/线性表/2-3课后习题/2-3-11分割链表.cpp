//思路和10题相同,这里不在选择返回两个链表，而是返回一个，另一个挂到来类的head上
//新表的创建使用头插法

#include "GetListByVector.h"

Node *Split(Node *head)
{
    Node *retHead = new Node(-1); //拆分下来的头节点
    Node *node = head->_next;
    while (node != nullptr)
    {
        Node *next = node->_next;
        if (next != nullptr)
        {
            node->_next = next->_next;
            node = node->_next;
            // next节点头插到ret链上
            next->_next = retHead->_next;
            retHead->_next = next;
        }
        else
        {
            node->_next = nullptr;
            node = node->_next;
        }
    }
    return retHead;
}

int main()
{
    // NodeListHead list({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
    // NodeListHead list({1, 2, 3});
    NodeListHead list({1});

    NodeListHead::PrintList(Split(list.head));
    list.PrintList();
    return 0;
}