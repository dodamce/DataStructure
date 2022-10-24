#include "GetListByVector.h"

//前后指针法删除有序链表的除重复元素,时间复杂度O(N).
//这里选择使用不带头链表实现
void DelReptElem(Node *head)
{
    Node *prev = nullptr;
    Node *left = head;
    Node *right = head->_next;
    while (left != nullptr)
    {
        while (right != nullptr && left->_val == right->_val)
        {
            prev = right;
            right = right->_next;
        }
        //留一个元素，将重复的元素链表单独拿出来删除
        if (left->_next != right)
        {
            Node *pos = left->_next;
            prev->_next = nullptr;
            NodeListNoHead::_DestroyNode(pos);
            left->_next = right;
        }

        left = right;
        if (right != nullptr)
            right = right->_next;
    }
}
int main()
{
    // NodeListNoHead list({1, 1, 2, 2, 3, 4, 5, 6, 6, 6, 7, 8});
    NodeListNoHead list({1, 1, 2, 2, 3, 4, 5, 6, 6, 6, 8, 8});
    // NodeListNoHead list({1, 1});
    DelReptElem(list._head);
    list.PrintList();
    return 0;
}