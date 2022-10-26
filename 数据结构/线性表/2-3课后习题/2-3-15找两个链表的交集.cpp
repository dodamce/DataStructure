//找到两个升序链表的交集，将这个链表放到first链表上

#include "GetListByVector.h"

void findComElem(Node *first, Node *second)
{
    //将first链表有效部分摘下来
    Node *node = first->_next;

    Node *tmpHead = node; //保存取出公共部分节点的剩下的节点
    Node *pos = first;    //保存公共节点链表的尾节点

    Node *ptr = second->_next;
    Node *prev = nullptr;
    while (ptr != nullptr && node != nullptr)
    {
        if (node->_val != ptr->_val)
        {
            //数值最小的向前走
            node->_val > ptr->_val ? (ptr = ptr->_next) : (prev = node, node = node->_next);
        }
        else
        {
            while (ptr != nullptr && node != nullptr && ptr->_val == node->_val)
            {
                if (prev == nullptr)
                {
                    //第一个元素就是公共部分
                    pos->_next = node;
                    node = node->_next;
                    //拆下的链表头要改变
                    tmpHead = node;
                    pos = pos->_next;
                    pos->_next = nullptr;
                }
                else
                {
                    pos->_next = node;
                    prev->_next = node->_next;
                    node->_next = nullptr;
                    pos = pos->_next;
                    node = prev->_next;
                }
                ptr = ptr->_next;
            }
            //这时可能两个链表还存在pos->_val的值，将其跳过
            while (ptr != nullptr && ptr->_val == pos->_val)
            {
                ptr = ptr->_next;
            }
            while (node != nullptr && node->_val == pos->_val)
            {
                prev = node;
                node = node->_next;
            }
        }
    }

    // 防止内存泄漏
    NodeListNoHead::_DestroyNode(tmpHead);
}

//时间复杂度O(N) 空间复杂度O(1)

int main()
{
    NodeListHead list({1, 2, 2, 3, 5, 6, 6, 7, 7, 10});
    NodeListHead next({0, 0, 1, 2, 3, 3, 3, 4, 5, 5, 6, 6, 8});
    findComElem(list.head, next.head);
    list.PrintList();
    return 0;
}