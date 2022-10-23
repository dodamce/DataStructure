#include "GetListByVector.h"

using namespace std;

void DelMinElemList(Node *head)
{
    int min = INT_MAX;
    Node *ptr = nullptr;
    Node *node = head;
    Node *del = head;
    while (node != nullptr)
    {
        if (node->_val < min)
        {
            min = node->_val;
            del = node;
        }
        ptr = node;
        node = node->_next;
    }
}

int main()
{
    NodeListHead list({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
    DelMinElemList(list.head);
    return 0;
}