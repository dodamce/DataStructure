//递归法输出链表值

#include "GetListByVector.h"

using namespace std;

void PrintByRecursion(Node *node)
{
    if (node == nullptr)
    {
        cout << "nullptr ";
        return;
    }
    PrintByRecursion(node->_next);
    cout << node->_val << " ";
}

int main()
{
    NodeListNoHead list({1, 2, 3, 4, 5, 6, 7, 8, 9});
    PrintByRecursion(list._head);
    return 0;
}
