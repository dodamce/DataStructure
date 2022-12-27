// 邻接矩阵法存储图结构

#include <iostream>
#include <assert.h>
#include <map>
#include <vector>
#include <stdio.h>
#include <queue>

#include "UnionFindSet.h"

// v:图顶点保存的值。w:边的权值 max:最大权值，代表无穷。flag=true代表有向图。否则就是无向图
template <class v, class w, w max = INT_MAX, bool flag = false>
class graph
{
private:
    std::vector<v> _verPoint;            // 顶点集合
    std::map<v, int> _indexMap;          // 顶点与下标的映射
    std::vector<std::vector<w>> _matrix; // 邻接矩阵

    int _getPosPoint(const v &point)
    {
        if (_indexMap.find(point) != _indexMap.end())
        {
            return _indexMap[point];
        }
        else
        {
            std::cout << point << " not found" << std::endl;
            return -1;
        }
    }

public:
    graph() = default;
    // 根据数组来开辟邻接矩阵
    graph(const std::vector<v> &src)
    {
        _verPoint.resize(src.size());
        for (int i = 0; i < src.size(); i++)
        {
            _verPoint[i] = src[i];
            _indexMap[src[i]] = i;
        }

        // 初始化邻接矩阵
        _matrix.resize(src.size());
        for (int i = 0; i < src.size(); i++)
        {
            _matrix[i].resize(src.size(), max);
        }
    }
    // 添加边的关系,输入两个点，以及这两个点连线边的权值。
    void AddEdge(const v &pointA, const v &pointB, const w &weight)
    {
        // 获取这个顶点在邻接矩阵中的下标
        int posA = _getPosPoint(pointA);
        int posB = _getPosPoint(pointB);
        _matrix[posA][posB] = weight;
        if (!flag)
        {
            // 无向图,邻接矩阵对称
            _matrix[posB][posA] = weight;
        }
    }

    // 打印邻接矩阵
    void PrintGraph()
    {
        // 打印顶点对应的坐标
        typename std::map<v, int>::iterator pos = _indexMap.begin();
        while (pos != _indexMap.end())
        {
            std::cout << pos->first << ":" << pos->second << std::endl;
            pos++;
        }
        std::cout << std::endl;

        // 打印边
        printf("  ");
        for (int i = 0; i < _verPoint.size(); i++)
        {
            std::cout << _verPoint[i] << " ";
        }
        printf("\n");

        for (int i = 0; i < _matrix.size(); i++)
        {
            std::cout << _verPoint[i] << " ";
            for (int j = 0; j < _matrix[i].size(); j++)
            {
                if (_matrix[i][j] == max)
                {
                    // 这条边不通
                    printf("∞ ");
                }
                else
                {
                    std::cout << _matrix[i][j] << " ";
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    // -------------------------------------Kruskal--------------------------------------------
    typedef graph<v, w, max, flag> self;

    // 代表图的一条边
    struct edge
    {
        size_t src;
        size_t dst;
        w weight;
        edge(size_t _src, size_t _dst, w _weight)
        {
            this->src = _src;
            this->dst = _dst;
            this->weight = _weight;
        }
    };

    // 小堆排序规则，从小到打排序
    struct rules
    {
        bool operator()(const edge &left, const edge &right)
        {
            return left.weight > right.weight;
        }
    };

    // 最小生成树，返回最小生成树权值，传入一个图，这个参数是输入输出参数，函数结束后，minTree是图的最小生成树
    w kruskal(self &minGraph)
    {
        size_t size = _verPoint.size();
        minGraph._verPoint = _verPoint;
        minGraph._indexMap = _indexMap;

        // 初始化最小生成树的邻接矩阵
        minGraph._matrix.resize(size);
        for (size_t i = 0; i < size; i++)
        {
            minGraph._matrix[i].resize(size, max);
        }

        std::priority_queue<edge, std::vector<edge>, rules> queue;

        // 将所有的边添加到优先级队列中,因为是无向图的边,所以只需要遍历一半数组即可
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (_matrix[i][j] != max)
                {
                    queue.push(edge(i, j, _matrix[i][j]));
                }
            }
        }

        // 选出n-1条边
        int dstSize = 0;
        w total = w();
        // 创建并查集来标记是否成环,大小为图顶点个数。
        UnionFindSet unionSet(size);

        while (!queue.empty())
        {
            edge MinEdge = queue.top();
            queue.pop();
            // 判断这条边顶点是否在并查集中，在并查集中构成环，不符合最小生成树定义。
            if (!unionSet.IsSameSet(MinEdge.src, MinEdge.dst))
            {
                // 打印选的边测试
                //std::cout << _verPoint[MinEdge.src] << "->" << _verPoint[MinEdge.dst] << " 权值：" << MinEdge.weight << "\n";

                minGraph.AddEdge(_verPoint[MinEdge.src], _verPoint[MinEdge.dst], MinEdge.weight);
                unionSet.Union(MinEdge.src, MinEdge.dst);

                dstSize += 1;
                total += MinEdge.weight;
            }
        }

        if (dstSize != size - 1)
        {
            // 没有找到生成树
            std::cout << "没有找到生成树" << std::endl;
            return w();
        }
        return total;
    }
};