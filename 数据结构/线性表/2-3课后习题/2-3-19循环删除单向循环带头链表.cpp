#include "GetListByVector.h"

//删除带头循环单链表最小值，最后删除头节点
void DelElem(SingleNode *&head)
{
    //找链表的最小值,保存最小值链表的前一个节点
    SingleNode *min = head->next;
    SingleNode *prev = head;
    SingleNode *min_prev = prev;
    SingleNode *node = head->next;
    while (head->next != head)
    {
        while (node != head)
        {
            if (min->data > node->data)
            {
                min_prev = prev;
                min = node;
                node = node->next;
            }
            else
            {
                prev = node;
                node = node->next;
            }
        }
        //删除最小值
        min_prev->next = min->next;
        std::cout << "删除的值为:" << min->data << std::endl;
        delete min;

        //重置指针
        min = head->next;
        prev = head;
        min_prev = prev;
        node = head->next;
    }
    //删除头节点
    SingleNode *tmp = head;
    head = nullptr;
    delete tmp;
}

int main()
{
    NodeListCircleSingleHead list({3, 0, 2, 5, 4, 7, 6, 1});
    list.PrintList();

    DelElem(list.head);
    return 0;
}