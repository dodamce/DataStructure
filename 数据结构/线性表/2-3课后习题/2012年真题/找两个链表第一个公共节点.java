import java.util.HashSet;

//这个题的思路和2-3-08相同，采用Java来书写，C++在2-3-08文件上，使用了两种方法

// leetcode链接:https://leetcode.cn/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/

//两种方法的时间复杂度都是O(N)

//   Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

class Solution {
    ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode nodeA = headA;
        ListNode nodeB = headB;
        while (nodeA != null) {
            lenA++;
            nodeA = nodeA.next;
        }
        while (nodeB != null) {
            lenB++;
            nodeB = nodeB.next;
        }
        nodeA = headA;
        nodeB = headB;
        // 长度长的先走|lenA-lenB|个
        if (lenA > lenB) {
            while (lenA != lenB) {
                nodeA = nodeA.next;
                lenA--;
            }
        }
        if (lenA < lenB) {
            while (lenA != lenB) {
                nodeB = nodeB.next;
                lenB--;
            }
        }
        // 一起走，直到找到共同节点
        while (nodeA != null && nodeB != null) {
            if (nodeA == nodeB) {
                return nodeA;
            }
            nodeA = nodeA.next;
            nodeB = nodeB.next;
        }
        return null;
    }
}

//方法二,利用哈希表保存一条链表的节点地址
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
class Solution2 {
    ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        HashSet<ListNode> set=new HashSet<ListNode>();
        //将第一条链表的所有值放到set中
        ListNode node=headA;
        while(node!=null){
            set.add(node);
            node=node.next;
        }
        while(headB!=null){
            if(set.contains(headB)){
                return headB;
            }
            headB=headB.next;
        }
        return null;
    }
}
