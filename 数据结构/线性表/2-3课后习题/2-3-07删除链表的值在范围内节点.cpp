#include "GetListByVector.h"
//遍历带头链表，删除节点，时间复杂度O(N)

//删除值范围[left,right]
void DelElem(Node *head, int left, int right)
{
    assert(left <= right); // left>right是直接停止程序运行
    Node *node = head->_next;
    Node *pnode = nullptr; //前一个节点

    while (node != nullptr)
    {
        Node *next = node->_next;
        if (node->_val <= right && node->_val >= left)
        {
            //删除这个节点
            if (pnode == nullptr)
            {
                //头删
                head->_next = next;
            }
            else
            {
                pnode->_next = next;
            }
            delete node;
            node = next;
        }
        else
        {
            pnode = node;
            node = next;
        }
    }
}

int main()
{
    NodeListHead list({1, 5, 2, 3, 4, 5, 6, 7, 8});
    // NodeListHead list({1, 1, 1});
    // NodeListHead list({1, 5, 2, 3, 4, 5, 6, 7, 8});
    DelElem(list.head, 1, 4);
    list.PrintList();
    return 0;
}