#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>

typedef char ValueType;

struct Data
{
    bool mark = false;     // 标记域，标记这条边是否被搜索过
    size_t ivex = -1;      // 为该边依附的两个顶点在循序表的位置
    Data *ilink = nullptr; // 指向下一条依附于ivex的边
    size_t jvex = -1;
    Data *jlink = nullptr;
    int info = INT_MAX; // 权值，默认为无穷
};

struct MatrixNode
{
    ValueType value = ValueType(); // 初始化节点类型int和char型为0,其他类型调用其默认构造函数
    Data *list = nullptr;
};

class AdjacencyMultilist
{
private:
    std::vector<MatrixNode> _matrix;
    // 图节点和在_matrix下标的映射
    std::unordered_map<ValueType, size_t> _hashMap;

    size_t _getValeTypePos(const ValueType &dst)
    {
        auto pos = _hashMap.find(dst);
        if (pos == _hashMap.end())
        {
            std::cout << "dst point not found" << std::endl;
            assert(pos != _hashMap.end());
        }
        return pos->second;
    }

public:
    AdjacencyMultilist(const std::vector<ValueType> &vet)
    {
        _matrix.resize(vet.size()); // 先开辟内存
        for (int i = 0; i < vet.size(); i++)
        {
            _matrix[i].value = vet[i];
            _hashMap[vet[i]] = i;
        }
    }

    /**
     * @brief 向无向图中添加边关系
     *
     * @param src 边起点
     * @param dst 边终点
     * @param info 边权值
     */
    void AddEdge(const ValueType &src, const ValueType &dst, int info)
    {
        // 找到这两个点在_matrix顺序表的位置
        size_t posSrc = _getValeTypePos(src);
        size_t posDst = _getValeTypePos(dst);

        // 创建边节点
        Data *edge = new Data;
        edge->ivex = posSrc;
        edge->jvex = posDst;
        edge->info = info;

        // 头插法插入
        edge->ilink = _matrix[posSrc].list;
        _matrix[posSrc].list = edge;

        edge->jlink = _matrix[posDst].list;
        _matrix[posDst].list = edge;
    }

    // /*
    //  * 删除(src,dst) 或者(dst,src)
    //  * 实现思路：
    //  * 1、从 src 顶点的链表出发，找到目标结点的直接前驱结点；
    //  * 2、从 dst 顶点的链表触发，找到目标结点的直接前驱结点；
    //  * 3、将目标结点从 src 顶点的链表中摘除，从 dst 顶点的链表中摘除
    //  * 4、删除目标结点
    //  */

    // void DelEdge(const ValueType &src, const ValueType &dst)
    // {
    //     size_t posSrc = _getValeTypePos(src);
    //     size_t posDst = _getValeTypePos(dst);
    //     Data *srcPrev = nullptr;
    //     Data *dstPrev = nullptr;
    //     Data *node = _matrix[posSrc].list;
    //     // 找src点的直接前驱
    //     while (node != nullptr && ((node->ivex == posSrc && node->jvex == posDst) || (node->ivex == posDst && node->jvex == posSrc)))
    //     {
    //         // 因为邻接多重表只能保存有向图，删除边，这两个方向都需要删除
    //         srcPrev = node;
    //         if (node->ivex == posSrc)
    //         {
    //             node = node->ilink;
    //         }
    //         else
    //         {
    //             node = node->jlink;
    //         }
    //     }
    //     // 找dst点前驱
    //     Data *jnode = _matrix[posDst].list;
    //     while (jnode != nullptr && ((jnode->ivex == posSrc && jnode->jvex == posDst) || (jnode->ivex == posDst && jnode->jvex == posSrc)))
    //     {
    //         dstPrev = jnode;
    //         if (jnode->ivex == posDst)
    //         {
    //             jnode = jnode->ilink;
    //         }
    //         else
    //         {
    //             jnode = jnode->jlink;
    //         }
    //     }

    //     if (node == nullptr || jnode == nullptr)
    //     {
    //         std::cout << "edge not exit" << std::endl;
    //         return;
    //     }

    //     // 将目标结点从 src 顶点的链表中摘除，从 dst 顶点的链表中摘除
    //     if (srcPrev == nullptr)
    //     {
    //         // 头删
    //         if (_matrix[posSrc].list->ivex == posSrc)
    //         {
    //             _matrix[posSrc].list = node->ilink;
    //         }
    //         else
    //         {
    //             _matrix[posSrc].list = node->ilink;
    //         }
    //     }
    //     else
    //     {
    //         if (srcPrev->ivex == posSrc)
    //         {
    //             if (node->ivex == posSrc)
    //             {
    //                 srcPrev->ilink = node->ilink;
    //             }
    //             else
    //             {
    //                 srcPrev->ilink = node->jlink;
    //             }
    //         }
    //         else
    //         {
    //             if (node->ivex == posSrc)
    //             {
    //                 srcPrev->jlink = node->ilink;
    //             }
    //             else
    //             {
    //                 srcPrev->jlink = node->jlink;
    //             }
    //         }
    //     }

    //     // 从 dst 顶点的链表中摘除
    //     if (dstPrev == nullptr)
    //     {
    //         // 头删
    //         if (_matrix[posDst].list->ivex == posDst)
    //         {
    //             _matrix[posDst].list = node->ilink;
    //         }
    //         else
    //         {
    //             _matrix[posDst].list = node->ilink;
    //         }
    //     }
    //     else
    //     {
    //         if (dstPrev->ivex == posDst)
    //         {
    //             if (jnode->ivex == posDst)
    //             {
    //                 dstPrev->ilink = node->ilink;
    //             }
    //             else
    //             {
    //                 dstPrev->ilink = node->jlink;
    //             }
    //         }
    //         else
    //         {
    //             if (jnode->ivex == posDst)
    //             {
    //                 dstPrev->jlink = jnode->ilink;
    //             }
    //             else
    //             {
    //                 dstPrev->jlink = jnode->jlink;
    //             }
    //         }
    //     }

    //     // 删除边
    //     delete node;
    //     _matrix[posSrc].list = nullptr;
    // }

    // 输出邻接多重表中包含的所有边
    void PrintGraph()
    {
        for (int i = 0; i < _matrix.size(); i++)
        {
            // 如果当前结点存在，且标志域为 0
            Data *p = _matrix[i].list;
            while (p && (p->mark == false))
            {
                // 输出该边，并将标志域置为 1
                printf("%c-%c 权值%d ", _matrix[p->ivex].value, _matrix[p->jvex].value, p->info);
                p->mark = true;
                if (p->ivex == i)
                {
                    p = p->ilink;
                }
                else
                {
                    p = p->jlink;
                }
            }
        }
        printf("\n");
    }
};