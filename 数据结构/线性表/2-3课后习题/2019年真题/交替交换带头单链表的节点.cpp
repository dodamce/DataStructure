#include "GetListByVector.h"

//先找到链表中间节点，后半节点逆置，前半个链表进行重新连接即可

//时间复杂度:O(N+N+N)=O(N)空间复杂度O(1)

void resList(Node *head)
{
    //找链表中间节点
    Node *mid = head->_next;
    Node *fast = head->_next;
    Node *prev = nullptr;
    while (fast != nullptr && fast->_next != nullptr)
    {
        prev = mid;
        fast = fast->_next->_next;
        mid = mid->_next;
    }
    if (prev == nullptr)
    {
        //没有进循环，说明链表只有头节点，或只有一个节点
        return;
    }
    prev->_next = nullptr; //将链表切成两段

    //逆置mid后的节点,头插法逆置
    Node *res = mid;
    Node *node = res->_next;
    res->_next = nullptr;
    while (node != nullptr)
    {
        Node *next = node->_next;
        node->_next = res;
        res = node;
        node = next;
    }

    //逆置后重新插入到前半个链表上即可。
    node = head->_next;
    prev = node;
    while (node != nullptr && res != nullptr)
    {
        Node *node_next = node->_next;
        Node *res_next = res->_next;

        node->_next = res;
        res->_next = node_next;
        prev = res;

        node = node_next;
        res = res_next;
    }
    //将剩下的节点连接上
    if (res != nullptr)
    {
        prev->_next = res;
    }
}

int main()
{
    // NodeListHead list({1, 2, 3, 4, 5});
    // NodeListHead list({1, 2});
    NodeListHead list({1, 2, 3, 4});
    // NodeListHead list({1});

    resList(list.head);
    list.PrintList();
    return 0;
}