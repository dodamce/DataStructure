#include "GetListByVector.h"

//原地逆置带头单链表
void reserve(Node *node, Node *head)
{
    if (nullptr == node->_next)
    {
        //记录转换后的第一个有效节点
        head->_next = node;
        return;
    }
    reserve(node->_next, head);
    // node->next指向的逆转后的尾节点
    node->_next->_next = node;
    //逆转后将这个节点的后置节点置空
    node->_next = nullptr;
}
//迭代法，取下头节点,使用剩下的链表节点头插法构造逆序链表

void reserve(Node *head)
{
    Node *ptr = head->_next;
    head->_next = nullptr;
    while (ptr != nullptr)
    {
        Node *next = ptr->_next;
        if (head->_next == nullptr)
        {
            //此时没有节点,需要注意清空ptr连接的原来的链表节点
            head->_next = ptr;
            ptr->_next = nullptr;
        }
        else
        {
            ptr->_next = head->_next;
            head->_next = ptr;
        }
        ptr = next;
    }
}

int main()
{
    // NodeListHead list({1, 2, 3, 4, 5, 6, 7, 8, 9});
    NodeListHead list({1, 4, 2, 5});
    // reserve(list.head->_next, list.head);
    reserve(list.head);
    list.PrintList();

    return 0;
}