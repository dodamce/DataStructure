#include "GetListByVector.h"

using namespace std;

//返回数组，调用vector的拷贝构造，所以函数结束，vector内存被销毁前会先拷贝给main方法的函数返回值接受方
//链表带头

//时间复杂度O(N)
vector<Node *> SplitList(Node *head)
{
    //第一个节点是奇数

    Node *oddly = new Node(-1); //头节点
    Node *even = new Node(-1);

    //摘头
    Node *node = head->_next;
    head->_next = nullptr;

    bool flag = true; // true：奇数 false：偶数
    Node *oddlyNode = oddly;
    Node *evenNode = even;
    while (node != nullptr)
    {
        Node *next = node->_next;
        if (flag)
        {
            oddlyNode->_next = node;
            node->_next = nullptr;
            oddlyNode = oddlyNode->_next;
            flag = false;
        }
        else
        {
            evenNode->_next = node;
            node->_next = nullptr;
            evenNode = evenNode->_next;
            flag = true;
        }
        node = next;
    }
    vector<Node *> ret;
    ret.emplace_back(oddly);
    ret.emplace_back(even);
    return ret;
}

int main()
{
    NodeListHead list({1});
    // NodeListHead list({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
    list.PrintList();
    vector<Node *> ret = SplitList(list.head);
    for (int i = 0; i < ret.size(); i++)
    {
        NodeListHead::PrintList(ret[i]);
        NodeListNoHead::_DestroyNode(ret[i]);
    }
    return 0;
}