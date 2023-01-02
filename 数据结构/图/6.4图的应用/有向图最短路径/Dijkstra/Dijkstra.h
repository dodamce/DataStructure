// 邻接矩阵法存储图结构

#include <iostream>
#include <assert.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

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

    //-------------------------------Dijkstra---------------------------
    /**
     * @brief 单源最短路径
     *
     * @param src 起点
     * @param dist dist保存src到各个顶点的最短距离
     * @param pPath pPath:保存最短路径的节点对应下标
     */
    void Dijkstra(const v &src, std::vector<w> &dist, std::vector<int> &pPath)
    {
        size_t pos = _getPosPoint(src);
        size_t size = _verPoint.size();
        pPath.resize(size, -1);
        dist.resize(size, max);

        dist[pos] = 0;    // 源顶点到自己本身最短距离为0
        pPath[pos] = pos; // 源顶点的最短路径的父节点是自己本身

        std::vector<bool> S(size, false); // 已经确定最短路径的顶点的集合

        for (size_t time = 0; time < size; time++)
        {
            // 选不在S集合 最短路径的顶点，更新其他路径
            int p = 0;
            w min = max;

            for (size_t i = 0; i < size; i++)
            {
                if (S[i] == false && dist[i] < min)
                {
                    p = i;
                    min = dist[i];
                }
            }

            // 把p放到S集合中
            S[p] = true;

            // src->p + p->p邻接节点 与 src ->p邻接节点权值相比较小，要更新
            for (size_t adP = 0; adP < size; adP++)
            {
                // 找到p点邻接顶点
                if (S[adP] == false && _matrix[p][adP] != max)
                {
                    if ((dist[p] + _matrix[p][adP]) < dist[adP])
                    {
                        dist[adP] = dist[p] + _matrix[p][adP];

                        // 更新最短路径父节点
                        pPath[adP] = p;
                    }
                }
            }
        }
    }

    /**
     * @brief 单源最短路径
     *
     * @param src 起点
     * @param dist dist保存src到各个顶点的最短距离
     */
    void Dijkstra(const v &src, std::vector<w> &dist)
    {
        std::vector<int> pPath;
        Dijkstra(src, dist, pPath);

        size_t pos = _getPosPoint(src);
        size_t size = _verPoint.size();
        for (size_t i = 0; i < size; i++)
        {
            if (i != pos)
            {
                std::vector<int> path;
                size_t dst_pos = i;
                std::cout << "最短路径为:";
                while (dst_pos != pos)
                {
                    path.push_back(dst_pos);
                    dst_pos = pPath[dst_pos];
                }
                path.push_back(pos);
                std::reverse(path.begin(), path.end());
                for (size_t j = 0; j < path.size(); j++)
                {
                    std::cout << _verPoint[path[j]];
                    if (j != path.size() - 1)
                    {
                        std::cout << "->";
                    }
                }
                std::cout << "长度: " << dist[i] << std::endl;
            }
        }
    }
};