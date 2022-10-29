// 带头单链表,删除值绝对值相同的节点。只保留重复的一个节点，两种方法
// 1. 时间复杂度O(N^2)空间复杂度O(N) 每个节点都需要和剩下的节点对比，删除重复的节点
// 2. 首次出现的节点的值放入set中，如果其他节点的值在set中，就要删除这个节点。时间复杂度O(N)空间复杂度O(N)

#include "GetListByVector.h"
#include <unordered_set>

//方法一:时间复杂度O(N^2)空间复杂度O(N)

void DelElem(Node *head)
{
    Node *node = head->_next;
    while (node != nullptr)
    {
        Node *prev = node;
        Node *move = node->_next;
        while (move != nullptr)
        {
            if (std::abs(move->_val) != std::abs(node->_val))
            {
                prev = move;
                move = move->_next;
            }
            else
            {
                //找到重复的节点
                prev->_next = move->_next;
                delete move;
                move = prev->_next;
            }
        }
        node = node->_next;
    }
}

//方法二:时间复杂度O(N) 空间复杂度O(N)
void DelElemBySet(Node *head)
{
    Node *node = head->_next;
    std::unordered_set<int> set;
    Node *prev = node;
    while (node != nullptr)
    {
        //第一次出现
        if (set.find(abs(node->_val)) == set.end())
        {
            set.insert(abs(node->_val));
            prev = node;
            node = node->_next;
        }
        else
        {
            //重复出现
            prev->_next = node->_next;
            delete node;
            node = prev->_next;
        }
    }
}

int main()
{
    NodeListHead list({1, 2, 3, -1, 2, -3, 4, 5, 3, -5});
    // NodeListHead list({-1, 2, 3, -1});
    // NodeListHead list({-1, 2, 3});
    // DelElem(list.head);
    DelElemBySet(list.head);
    list.PrintList();
    return 0;
}
