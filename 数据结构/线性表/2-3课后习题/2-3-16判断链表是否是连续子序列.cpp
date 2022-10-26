//判断B链表是否是A链表的连续子序列.这里没有按照串匹配算法KMP优化,时间复杂度O(N^2)
#include "GetListByVector.h"

//两个链表不带头
bool IsChild(Node *src, Node *dest)
{
    Node *begin = src;
    Node *restart = dest;
    while (begin != nullptr)
    {
        while (dest != nullptr && src != nullptr && src->_val == dest->_val)
        {
            src = src->_next;
            dest = dest->_next;
        }
        if (dest == nullptr)
        {
            return true;
        }
        begin = begin->_next;
        src = begin;
        dest = restart;
    }
    return false;
}

int main()
{
    NodeListNoHead list({1, 2, 3, 4, 5, 6});
    NodeListNoHead next({3, 5});
    std::cout << IsChild(list._head, next._head);
    return 0;
}