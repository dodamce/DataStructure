#include "GetListByVector.h"

//两个指针，首先让两个指针相差k个节点,之后一起走,直到前面的节点到空，后面的节点就是这个链表的倒数第k个节点
//单链表带头
int findKNode(Node *head, size_t size)
{
    Node *tail = head;
    for (int i = 0; i < size; i++)
    {
        tail = tail->_next;
        if (tail == NULL)
        {
            std::cout << "链表长度小于size" << std::endl;
            return 0;
        }
    }
    Node *node = head;
    while (tail != nullptr)
    {
        node = node->_next;
        tail = tail->_next;
    }
    std::cout << "倒数第" << size << "个节点的值为" << node->_val << std::endl;
    return 1;
}

int main()
{
    NodeListHead list({1});
    findKNode(list.head, 1);
    return 0;
}