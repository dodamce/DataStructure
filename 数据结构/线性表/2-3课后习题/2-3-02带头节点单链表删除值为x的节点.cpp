#include "GetListByVector.h"

using namespace std;

//遍历法删除链表值为x的节点
Node *DelElemByTravel(Node *head, int target)
{
    Node *prev = nullptr;
    Node *node = head;
    while (node != nullptr)
    {
        if (node->_val == target)
        {
            if (node == head)
            {
                head = head->_next;
                delete node;
                node = head;
            }
            else
            {
                prev->_next = node->_next;
                delete node;
                node = prev->_next;
            }
        }
        else
        {
            prev = node;
            node = node->_next;
        }
    }
    return head;
}

int main()
{
    NodeListHead list({2, 2, 3, 1, 2, 3, 2, 2, 5, 6, 3, 2});
    list.PrintList();
    DelElemByTravel(list.head, 2);
    list.PrintList();
}