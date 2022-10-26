//两个带头有序链表的公共数字构造新链表,不破坏原来链表的节点

#include "GetListByVector.h"

Node *MergeList(Node *first, Node *second)
{
    Node *head = new Node(-1); //头节点
    Node *node = head;
    Node *firstPos = first->_next;
    Node *secondPos = second->_next;
    while (firstPos != NULL && secondPos != NULL)
    {
        if (firstPos->_val != secondPos->_val)
        {
            //数值最小的向前走
            if (firstPos->_val > secondPos->_val)
            {
                secondPos = secondPos->_next;
            }
            else
            {
                firstPos = firstPos->_next;
            }
        }
        else
        {
            //不破坏原来的结构
            while (firstPos != nullptr && secondPos != nullptr && firstPos->_val == secondPos->_val)
            {
                Node *newNode = new Node(firstPos->_val);
                node->_next = newNode;
                node = newNode;
                firstPos = firstPos->_next;
                secondPos = secondPos->_next;
            }
            //这时可能两个链表还存在firstPos->_val的值，将其跳过
            while (firstPos != nullptr && firstPos->_val == node->_val)
            {
                firstPos = firstPos->_next;
            }
            while (secondPos != nullptr && secondPos->_val == node->_val)
            {
                secondPos = secondPos->_next;
            }
        }
    }
    node->_next = nullptr;
    return head;
}

//时间复杂度O(N),空间复杂度O(N)(返回了一个新的链表)

int main()
{
    NodeListHead list({1, 2, 2, 3, 4, 4, 4, 4, 6});
    NodeListHead next({0, 0, 0, 1, 2, 3, 3, 4, 4, 4});
    Node *node = MergeList(list.head, next.head);
    NodeListHead::PrintList(node);
    NodeListNoHead::_DestroyNode(node);
    return 0;
}
