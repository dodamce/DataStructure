//利用leetcode链接来做题
// https://leetcode.cn/problems/c32eOV/
//思路:首先如果链表带环的话,快指针会在环内追慢指针
/**
 * 快指针每次走两个
 * 慢指针每次走一个
 * 走一次，二者的相对距离就减少1,最后一定可以在环内相遇
 *
 * 此时从相遇点和链表头节点开始,两个指针同步走动,最终相遇点一定是环入口点
 * 思路:https://blog.csdn.net/dodamce/article/details/115665743?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166692115916782414968039%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fblog.%2522%257D&request_id=166692115916782414968039&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~first_rank_ecpm_v1~rank_v31_ecpm-2-115665743-null-null.nonecase&utm_term=%E5%88%A4%E6%96%AD&spm=1018.2226.3001.4450
 */
#include <unordered_set>

// 时间复杂度O(N)空间复杂度O(1)
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        do
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        //链表带环
        ListNode *node = head;
        ListNode *ptr = fast;

        //两个指针同步走,相遇点就是环入口
        while (node != ptr)
        {
            node = node->next;
            ptr = ptr->next;
        }
        return ptr;
    }
};

//方法二：死循环遍历，将遍历的节点，如果集合没有，则放到集合中。如果有说明就是环入口节点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//时间复杂度O(N)空间复杂度O(N)
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        std::unordered_set<ListNode *> set;
        ListNode *node = head;
        while (true)
        {
            if (node == nullptr)
            {
                return nullptr;
            }
            if (set.find(node) == set.end())
            {
                set.insert(node);
            }
            else
            {
                return node;
            }
            node = node->next;
        }
        //不可能走到这里
        return nullptr;
    }
};
