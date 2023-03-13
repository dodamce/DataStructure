/**
 * @brief 链表结构 简单选择排序关键字
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

struct Node
{
    int _val;
    Node *next;
    Node(int val) : _val(val), next(nullptr) {}
};

class List
{
public:
    Node *_head = nullptr;
    size_t _size = 0;

    List() = default;

    List(std::vector<int> &vet)
    {
        for (auto &elem : vet)
        {
            insert(elem);
        }
    }

    void insert(int val)
    {
        if (_head == nullptr)
        {
            _head = new Node(val);
        }
        else
        {
            // 头插法
            Node *node = new Node(val);
            node->next = _head;
            _head = node;
        }
        _size += 1;
    }

    // 寻找一个节点的父节点
    Node *findPrev(Node *node)
    {
        if (node == nullptr)
        {
            // 返回尾节点
            Node *ptr = _head;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            return ptr;
        }
        else
        {
            Node *prev = nullptr;
            Node *ptr = _head;
            while (ptr != nullptr)
            {
                if (ptr->_val != node->_val)
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
                else
                {
                    break;
                }
            }
            return prev;
        }
    }

    Node *operator[](int index)
    {
        Node *ptr = _head;
        for (int i = 0; i < index; i++)
        {
            assert(ptr != nullptr);
            ptr = ptr->next;
        }
        return ptr;
    }

    // 思路比较复杂，这里可以选择创建一条新链表来简化操作
    void SelectSort()
    {
        for (int i = 0; i < _size; i++)
        {
            // 每次将最大节点移动到链表尾部
            Node *max = nullptr;
            Node *node = _head;
            for (int j = 0; j < _size - i; j++)
            {
                if (max == nullptr)
                {
                    max = _head;
                }
                else
                {
                    if (node->_val > max->_val)
                    {
                        max = node;
                    }
                }
                node = node->next;
            }

            // 找到最大值节点将节点移动到链表尾部
            Node *prev = findPrev(max);
            Node *node_prev = findPrev(node);
            if (node_prev == max)
            {
                // 此时已经处于有序状态.进行下一轮
                //  display();
                continue;
            }
            else
            {
                if (prev != nullptr)
                {
                    prev->next = max->next;
                }
                else
                {
                    // 头节点，需要换头
                    _head = max->next;
                }
                max->next = node;
                node_prev->next = max;
                // display();
            }
        }
    }

    void SelectSort(bool useList)
    {
        // 创建新链表，整理好后和原链表交换即可
        Node *node = nullptr;
        for (int i = 0; i < _size; i++)
        {
            Node *max = _head;
            Node *ptr = _head;
            for (int j = 0; j < _size - i; j++)
            {
                // 每次选择最大节点头插到node上
                if (max->_val < ptr->_val)
                {
                    max = ptr;
                }
                ptr = ptr->next;
            }

            if (max == _head)
            {
                _head = max->next;
            }
            else
            {
                Node *prev = findPrev(max);
                prev->next = max->next;
            }
            max->next = node;
            node = max;
        }
        _head = node;
    }

    void display()
    {
        Node *ptr = _head;
        while (ptr != nullptr)
        {
            std::cout << ptr->_val << " ";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> vet = {3, 2, 5, 1, 6, 0, 9};
    List list(vet);
    list.display();
    // list.SelectSort();
    list.SelectSort(true);
    list.display();
    return 0;
}
