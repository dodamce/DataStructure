//依次递增输出值,并且删除节点,不使用额外空间,链表带头
#include "GetListByVector.h"

using namespace std;

//时间复杂度O(N^2)空间复杂度O(1)
void coutList(Node *head)
{
    Node *node = head->_next;
    cout << "头-> ";
    Node *min = node;
    Node *front_min = nullptr;
    while (node->_next != nullptr)
    {
        while (node->_next != nullptr)
        {
            //找最小节点
            if (min->_val > node->_next->_val)
            {
                front_min = node;
                min = node->_next;
            }
            node = node->_next;
        }

        //打印最小值
        cout << min->_val << "-> ";
        //删除最小值这个节点
        if (front_min != nullptr)
            front_min->_next = min->_next;
        else
            //有序的,front_min没有更新
            head->_next = min->_next;
        delete min;
        //重置min front_min节点和node节点
        min = head->_next;
        node = head->_next;
        front_min = nullptr;
    }
    //此时还剩下最后一个节点没有处理，此时node这个节点，直接将这个节点打印出来并删除即可
    cout << node->_val << "-> "
         << "null " << endl;
    delete node;

    //所有节点全部处理完毕，链表置空
    head->_next = nullptr;
}

int main()
{
    // NodeListHead list({2, 3, 3, 4, 1});
    // NodeListHead list({1});
    // NodeListHead list({2, 3, 3, 4});
    NodeListHead list({4, 3, 5, 3, 1, 5, 7, 2, 2, 3, 0, 8, 1, 10});
    list.PrintList();
    coutList(list.head);
    list.PrintList();
    return 0;
}