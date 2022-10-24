//时间复杂度O(m+n)
#include "GetListByVector.h"

//原地逆置无头链表
void reserve(Node *node, Node *&head)
{
    if (node->_next == nullptr)
    {
        head = node;
        return;
    }
    reserve(node->_next, head);
    node->_next->_next = node;
    node->_next = nullptr;
}

//返回一个带头链表,合并两个无头升序链表为一个带头降序链表
//时间复杂度O(m+n)
Node *MergeList(Node *&left, Node *&right)
{
    //将传入的两个链表置空
    Node *first = left;
    Node *second = right;
    left = nullptr;
    right = nullptr;

    Node *head = new Node(-1);
    while (first != nullptr && second != nullptr)
    {
        //每次找两个值小的节点头插到链表上
        if (first->_val <= second->_val)
        {
            Node *next = first->_next;
            first->_next = head->_next;
            head->_next = first;
            first = next;
        }
        else
        {
            Node *next = second->_next;
            second->_next = head->_next;
            head->_next = second;
            second = next;
        }
    }
    if (first != nullptr)
    {
        //将剩下链表逆置头插到链表上
        Node *tail = first;
        reserve(first, first);
        // NodeListNoHead::PrintList(first);
        tail->_next = head->_next;
        head->_next = first;
    }
    else if (second != nullptr)
    {
        Node *tail = second;
        reserve(second, second);
        // NodeListNoHead::PrintList(second);
        tail->_next = head->_next;
        head->_next = second;
    }
    return head;
}

int main()
{
    NodeListNoHead list({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
    NodeListNoHead list2({1, 1, 2, 2, 3, 4, 5, 6, 6, 6, 8, 8});
    // NodeListNoHead list({1});
    // NodeListNoHead list2({2});
    Node *ret = MergeList(list._head, list2._head);
    NodeListHead::PrintList(ret);
    NodeListNoHead::_DestroyNode(ret);
    return 0;
}