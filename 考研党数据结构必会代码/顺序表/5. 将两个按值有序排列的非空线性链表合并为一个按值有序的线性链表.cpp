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

ListNode *MergeList(ListNode *left, ListNode *right)
{
    ListNode *head = new ListNode(-1);
    ListNode *tail = head;
    while (left != nullptr && right != nullptr)
    {
        if (left->val < right->val)
        {
            tail->next = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }
    tail->next = left == nullptr ? right : left;
    return head->next;
}

int main(int argc, char const *argv[])
{
    ListNode *left = InitList({1, 2, 3, 4, 5});
    ListNode *right = InitList({2, 3, 4, 8});
    PrintList(MergeList(left, right));
    return 0;
}
