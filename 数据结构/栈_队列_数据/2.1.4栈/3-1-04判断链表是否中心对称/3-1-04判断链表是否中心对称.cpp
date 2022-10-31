//把链表对半分成两部分，前部分进栈。后部分出栈，如果最后栈为空，说明是中心对称的
//注意: xyx 中间y不要进栈,需要判断这个栈是奇数还是偶数个
//链表不带头
#include "GetListByVector.h"

#include <stack>

bool isSymmetry(Node *head)
{
    //找链表中间节点，并统计链表节点数目
    Node *slow = head;
    Node *fast = head;
    size_t size = 0; //记录链表有几个节点
    while (fast != nullptr && fast->_next != nullptr)
    {
        fast = fast->_next->_next;
        size += 2;
        slow = slow->_next;
    }
    if (fast != nullptr)
    {
        //剩下最后一个节点没有统计
        size += 1;
    }

    //如果size是奇数，[1,slow)节点进栈  如果size是偶数[1,slow)节点进栈

    std::stack<int> st;
    Node *node = head;
    while (node != slow)
    {
        st.push(node->_val);
        node = node->_next;
    }
    //奇数出栈元素从slow->next开始 ,偶数出栈元素从slow开始
    Node *begin = slow;
    if (size % 2 != 0)
    {
        begin = begin->_next;
    }
    while (begin != nullptr)
    {
        if (begin->_val != st.top())
        {
            return false;
        }
        st.pop();
        begin = begin->_next;
    }

    return st.empty();
}

int main()
{
    // NodeListNoHead list({1});
    // NodeListNoHead list({1, 1});
    // NodeListNoHead list({1, 2, 3});
    // NodeListNoHead list({1, 2, 1});
    NodeListNoHead list({1, 2, 2, 1});
    std::cout << isSymmetry(list._head) << std::endl;
    return 0;
}