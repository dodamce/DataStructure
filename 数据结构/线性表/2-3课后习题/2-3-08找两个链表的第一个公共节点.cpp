//因为不方便构造有公共节点的链表，这里使用leetcode的题来解答

// leetcode链接:https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/

/**
 *
 * 思路一:
 * 先分别统计两个个链表的长度
 * 长的链表先走到和短的链表相同的长度的位置
 * 然后两个人一起走，当走到地址相同的节点时，说明找到了第一个公共节点
 *
 * 两个链表都要遍历两次，时间复杂度:O(4N)=O(N) 空间复杂度O(1)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lengthA = 0;
        int lengthB = 0;

        ListNode *A = headA;
        ListNode *B = headB;
        while (A != nullptr)
        {
            lengthA++;
            A = A->next;
        }
        while (B != nullptr)
        {
            lengthB++;
            B = B->next;
        }
        A = headA;
        B = headB;
        while (lengthA < lengthB)
        {
            B = B->next;
            lengthB--;
        }
        while (lengthA > lengthB)
        {
            A = A->next;
            lengthA--;
        }

        //一起走,直到找到地址相同的节点
        while (A != nullptr && B != nullptr)
        {
            if (A == B)
            {
                return A;
            }
            A = A->next;
            B = B->next;
        }
        return nullptr;
    }
};

//思路二:将一个链表放入集合中,用另一个链表找集合内的值，找打的话就返回，空间复杂度O(N)，时间复杂度O(N)遍历两次

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <unordered_set>

using namespace std;

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> set;
        while (headA != nullptr)
        {
            set.insert(headA);
            headA = headA->next;
        }

        //从集合中找元素
        while (headB != nullptr)
        {
            if (set.find(headB) != set.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};