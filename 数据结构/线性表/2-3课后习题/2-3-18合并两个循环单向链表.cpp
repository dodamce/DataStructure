//两个循环单向链表first second 将second合并到first
#include "GetListByVector.h"

using namespace std;

void MergeList(SingleNode *first, SingleNode *&second)
{
    //遍历到first的链表末尾
    SingleNode *node = first;
    while (node->next != first)
    {
        node = node->next;
    }
    //遍历second找second的尾
    SingleNode *nodeSec = second;
    while (nodeSec->next != second)
    {
        nodeSec = nodeSec->next;
    }
    node->next = second;
    nodeSec->next = first;

    //摘掉second节点
    second = nullptr;
}

int main()
{
    NodeListCircleSingle first({1, 2, 3, 4, 5, 6});
    NodeListCircleSingle second({2, 3, 4, 5});
    MergeList(first.head, second.head);
    first.PrintList();
    return 0;
}