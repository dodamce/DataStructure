#include "GetListByVector.h"

using namespace std;

/**
 * @brief 函数返回链表的最小值
 *
 * @param head
 */

int DelMinElemList(Node *head)
{
    int min = INT_MAX;
    Node *ptr = head->_next;
    Node *node = head->_next;
    Node *del = head->_next;
    while (node != nullptr)
    {
        if (node->_val < min)
        {
            min = node->_val;
            del = node;
        }
        node = node->_next;
    }
    //判断如果此时ptr和del相同，说明删除的是第一个节点
    if (del == ptr)
    {
        head->_next = del->_next;
        delete del;
    }
    else
    {
        //找打要删除节点的前驱指针
        while (ptr->_next != del)
        {
            ptr = ptr->_next;
        }
        //删除del节点；
        ptr->_next = del->_next;
        delete del;
    }
    return min;
}

int main()
{
    NodeListHead list({0, 4, 3, 4, 5, 6, 1, 8, 9, 10, 11, 11});
    DelMinElemList(list.head);
    list.PrintList();
    return 0;
}