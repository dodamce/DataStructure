/**
孩子表示法存储普通树采用的是 "顺序表+链表" 的组合结构，其存储过程是：从树的根节点开始，使用顺序表依次存储树中各个节点。
需要注意，与双亲表示法不同的是，孩子表示法会给各个节点配备一个链表，用于存储各节点的孩子节点位于顺序表中的位置。
如果节点没有孩子节点（叶子节点），则该节点的链表为空链表。

链表存储的值不是数据本身，而是数据在数组中的位置
 *
 */

#include <vector>
#include <iostream>
#include <stdio.h>
#include <assert.h>

struct listNode
{
    int pos;
    listNode *next = nullptr;
    listNode(int _pos) : pos(_pos) {}
};

struct ChildList
{
    int data;
    listNode *node = nullptr;
    ChildList(int _data) : data(_data){};
};

//让用户构建树
class Tree
{
    std::vector<ChildList> node;

public:
    Tree()
    {
        std::cout << "输入树的节点个数" << std::endl;
        int capacity = 0;
        std::cin >> capacity;
        int size = 0;
        while (size < capacity)
        {
            std::cout << "输入数组下标" << size << "的值";
            int data = 0;
            std::cin >> data;
            ChildList list(data);
            std::cout << "输入这个节点有几个孩子" << std::endl;
            int child = 0;
            std::cin >> child;
            listNode *next = nullptr;
            for (int i = 1; i <= child; i++)
            {
                printf("输入第%d个孩子节点在数组的下标", i);
                int pos = 0;
                std::cin >> pos;
                listNode *node = new listNode(pos);
                if (list.node == nullptr)
                {
                    list.node = node;
                    next = node;
                }
                else
                {
                    next->next = node;
                    next = next->next;
                }
            }
            node.push_back(list);
            size++;
        }
    }

    //尽可能的表示树结构
    void DisPlay()
    {
        //打印树结构
        std::vector<std::vector<int>> msg; //保存树的结构
        //读取树每层的结构
        std::vector<int> pos(1, 0); //存放下一层节点的位置
        std::vector<int> prev;

        int max = 0; //记录层最大节点个数
        for (int i = 0; i < this->node.size(); i++)
        {
            std::vector<int> data;
            for (int i = 0; i < pos.size(); i++)
            {
                data.push_back(this->node[pos[i]].data);
            }
            max = data.size() > max ? data.size() : max;
            msg.push_back(data);
            //修改存放下一层pos数组
            prev = pos;
            pos.clear();
            for (int i = 0; i < prev.size(); i++)
            {
                listNode *node = this->node[prev[i]].node;
                while (node != nullptr)
                {
                    pos.push_back(node->pos);
                    node = node->next;
                }
            }
        }

        //如果层节点小于max先打印
        for (int i = 0; i < msg.size(); i++)
        {
            int size = msg[i].size();
            if (size < max)
            {
                //打印空格
                for (int j = 0; j <= (max - size) / 2; j++)
                {
                    std::cout << " ";
                }
            }
            for (int k = 0; k < size; k++)
            {
                std::cout << msg[i][k] << " ";
            }
            std::cout << "\n";
        }
    }

    //查找树节点值data的子节点
    void findChild(int data)
    {
        int pos = findPos(data);
        if (pos == -1)
        {
            printf("树中没有此元素\n");
        }
        else
        {
            listNode *list = this->node[pos].node;
            printf("%d的子节点值为:\n", data);
            while (list != nullptr)
            {
                std::cout << this->node[list->pos].data << " ";
                list = list->next;
            }
            std::cout << "\n";
        }
    }

private:
    int findPos(int data)
    {
        for (int i = 0; i < this->node.size(); i++)
        {
            if (this->node[i].data == data)
            {
                return i;
            }
        }
        return -1;
    }
};
