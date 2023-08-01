#include <vector>
#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int _val) : val(_val), next(nullptr) {}
};

typedef struct Node ListNode;

ListNode *InitList(const vector<int> &vet)
{
    ListNode *head = new ListNode(-1);
    Node *tail = head;
    for (int i = 0; i < vet.size(); i++)
    {
        tail->next = new Node(vet[i]);
        tail = tail->next;
    }
    ListNode *next = head->next;
    delete head;
    return next;
}

void PrintList(ListNode *list)
{
    while (list != nullptr)
    {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

ListNode *CopyList(ListNode *src)
{
    ListNode *dst = nullptr;
    if (src == nullptr)
    {
        return nullptr;
    }
    else
    {
        dst = new ListNode(src->val);
        dst->next = CopyList(src->next);
        return dst;
    }
}

int main(int argc, char const *argv[])
{
    ListNode *list = InitList({1, 2, 2, 3, 4});
    ListNode *copy = CopyList(list);
    PrintList(copy);
    return 0;
}
