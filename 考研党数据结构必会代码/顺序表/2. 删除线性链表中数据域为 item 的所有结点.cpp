// #include <list>
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

using namespace std;
/**
using C++11
 */
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
void PurgeItem(ListNode *list, int val)
{
    // 空节点返回
    if (list == nullptr)
    {
        return;
    }
    Node *prev = list;
    Node *cur = prev->next;
    while (cur != nullptr)
    {
        Node *next = cur->next;
        if (cur->val == val)
        {
            prev->next = cur->next;
            delete cur;
            cur = next;
        }
        else
        {
            prev = cur;
            cur = next;
        }
    }
    // 验证第一个节点
    if (list->val == val)
    {
        ListNode *head = list->next;
        delete list;
        list = head;
    }
    // 打印测试
    while (list != nullptr)
    {
        cout << list->val << " ";
        list = list->next;
    }
}

int main(int argc, char const *argv[])
{
    // ListNode *list = InitList({2, 2, 2, 2, 2});
    ListNode *list = InitList({2, 2, 2, 3, 4});
    PurgeItem(list, 2);
    return 0;
}
