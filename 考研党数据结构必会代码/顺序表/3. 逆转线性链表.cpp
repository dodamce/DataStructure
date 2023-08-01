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

// 递归解法
ListNode *reverse(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *next = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return next;
}

// 非递归解法
ListNode *reverse_display(ListNode *head)
{
    // 对头节点进行头插法
    ListNode *newHead = head;
    ListNode *node = head->next;
    newHead->next = nullptr;

    while (node != nullptr)
    {
        ListNode *next = node->next;
        node->next = newHead;
        newHead = node;
        node = next;
    }
    return newHead;
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

int main(int argc, char const *argv[])
{
    ListNode *list = InitList({1, 2, 2, 3, 4});
    list = reverse(list);
    PrintList(list);
    list = reverse_display(list);
    PrintList(list);
    return 0;
}
