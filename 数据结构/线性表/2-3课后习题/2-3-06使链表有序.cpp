#include "GetListByVector.h"

//链表排序，链表带头 ，使用插入排序算法排序
void sortListByVet(Node *head)
{
    //拿下头节点
    Node *ptr = head->_next;
    head->_next = nullptr;

    while (ptr != nullptr)
    {
        Node *node = head->_next; //遍历新链表，找到适合的位置插入
        Node *font = nullptr;

        //拿下原链表的一个节点
        Node *next = ptr->_next;
        ptr->_next = nullptr;

        //这里让它是稳定排序，所以为<=
        while (node != nullptr && node->_val <= ptr->_val)
        {
            font = node;
            node = node->_next;
        }

        //找到插入的位置，进行插入
        if (font != nullptr)
        {
            ptr->_next = node;
            font->_next = ptr;
        }
        else
        {
            // 头插
            head->_next = ptr;
            ptr->_next = node;
        }
        ptr = next;
    }
}

int main()
{
    // NodeListHead list({6, 5, 4, 3, 2, 2, 4, 1, 4, 7, 8});
    // NodeListHead list({1});
    NodeListHead list({1, 2, 3});
    sortListByVet(list.head);
    list.PrintList();
    return 0;
}