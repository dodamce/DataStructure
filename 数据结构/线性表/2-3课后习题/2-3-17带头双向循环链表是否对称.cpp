#include "GetListByVector.h"

using namespace std;

//判断带头双向循环链表是否对称,时间复杂度O(N)
bool SymList(CircleNode *head)
{
    CircleNode *left = head->next;
    CircleNode *right = head->prev;
    while (left != right)
    {
        if (left->data != right->data)
        {
            return false;
        }
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main()
{
    NodeListHeadCircle list({1, 2, 3, 3, 2, 1});
    NodeListHeadCircle next({1});
    NodeListHeadCircle three({1, 2, 3, 1, 1});
    cout << SymList(list.head) << " " << SymList(next.head) << " " << SymList(three.head) << std::endl;
    return 0;
}