#include "GetListByVector.h"

using namespace std;

// 带头双向链表
struct NodeBoth
{
    NodeBoth *next = nullptr;

    NodeBoth *prev = nullptr;

    int freq = 0; //访问频度域
    int data;
    NodeBoth(int d) : data(d) {}
};

class NodeListBoth
{
public:
    NodeBoth *head;
    NodeListBoth(const std::vector<int> &vet)
    {
        head = new NodeBoth(-1); //头节点
        NodeBoth *node = head;
        for (int i = 0; i < vet.size(); i++)
        {
            NodeBoth *newNode = new NodeBoth(vet[i]);
            node->next = newNode;
            newNode->prev = node;
            node = newNode;
        }
    }
    void PrintList()
    {
        if (head == nullptr)
        {
            std::cout << "空 ";
        }
        NodeBoth *node = head->next;
        std::cout << "头 ->";
        while (node != nullptr)
        {
            std::cout << node->data << "-> ";
            node = node->next;
        }
        std::cout << "null " << std::endl;
    }
    ~NodeListBoth()
    {
        NodeBoth *node = head;
        while (node != nullptr)
        {
            NodeBoth *next = node->next;
            delete node;
            node = next;
        }
    }
};

//让节点值为target的freq+1,并且时钟让链表按照访问频度降序,是频繁访问的节点排在前面,返回找到的节点
NodeBoth *Locate(NodeBoth *&list, int target)
{
    //先找第一个值为target的节点
    NodeBoth *node = list->next;
    while (node != nullptr)
    {
        if (node->data == target)
        {
            break;
        }
        node = node->next;
    }
    if (node == nullptr)
    {
        std::cout << "没有找到要访问的节点" << std::endl;
        return nullptr;
    }
    node->freq += 1;
    //向前找第一个freq比node大的
    NodeBoth *prev = node;
    while (prev != list && prev->freq <= node->freq)
    {
        prev = prev->prev;
    }
    //更改node节点位置
    NodeBoth *next = node->next;
    if (next != nullptr)
    {
        next->prev = node->prev;
        node->prev->next = next;
    }
    else
    {
        node->prev->next = nullptr;
    }

    if (prev == list)
    {
        //出现次数最大，第一个
        node->next = list->next;
        list->next->prev = node;
        list->next = node;
        node->prev = list;
    }
    else
    {
        node->next = prev->next;
        prev->next->prev = node;

        prev->next = node;
        node->prev = prev;
    }
    return node;
}

int main()
{
    NodeListBoth list({1, 2, 3, 4});
    // Locate(list.head, 3);
    // list.PrintList();
    // Locate(list.head, 4);
    // list.PrintList();
    // Locate(list.head, 2);
    // Locate(list.head, 2);
    // list.PrintList();
    // Locate(list.head, 1);
    // list.PrintList();
    // Locate(list.head, 1);
    // list.PrintList();
    // Locate(list.head, 2);
    // list.PrintList();
    // Locate(list.head, 3);
    Locate(list.head, 4);
    list.PrintList();
    return 0;
}