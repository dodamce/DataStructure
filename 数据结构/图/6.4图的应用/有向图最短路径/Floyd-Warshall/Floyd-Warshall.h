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

    //-------------------------------Floyd-Warshall---------------------------
    /**
     * @brief 多源最短路径
     *
     * @param vDist （记录源顶点到其他顶点的最短路径）数组应该是二维数组。
     * @param vPath （通过双亲表示法记录最短路径的节点）也应该是二维数组。
     */
    void FloydWarShall(std::vector<std::vector<w>> &vDist, std::vector<std::vector<int>> &vPath)
    {
        size_t size = _verPoint.size();

        // 初始化顶点距离矩阵和路径矩阵
        vDist.resize(size);
        vPath.resize(size);
        for (size_t i = 0; i < size; i++)
        {
            vDist[i].resize(size, max);
            vPath[i].resize(size, -1);
        }

        // 直接相连的边更新初始化

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if (_matrix[i][j] != max)
                {
                    vDist[i][j] = _matrix[i][j];
                    vPath[i][j] = i; // i->j起点是i点
                }
                if (i == j)
                {
                    vDist[i][j] = w();
                }
            }
        }

        // 最短路径的更新i->{其他顶点}->j
        // k作为中间点，尝试更新i->j的路径
        for (size_t k = 0; k < size; k++)
        {
            for (size_t i = 0; i < size; i++)
            {
                for (size_t j = 0; j < size; j++)
                {
                    if (vDist[i][k] != max && vDist[k][j] != max)
                    {
                        if (vDist[i][k] + vDist[k][j] < vDist[i][j])
                        {
                            // 经过k点更短，更新长度
                            vDist[i][j] = vDist[i][k] + vDist[k][j];
                            // 修改父亲节点
                            // 找上一个与j邻接的节点
                            // k->j 如果k与j直接相连，则vPath[i][j]=k
                            // 但是k->j不一定直接相连 k->...->x->j则vPath[i][j]=x,就是vPath[k][j]
                            vPath[i][j] = vPath[k][j];
                        }
                    }
                }
            }
        }
    }

    void _PrintShortLine(const v &src, std::vector<w> &dist, std::vector<int> pPath)
    {
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

    void PrintFloyd(std::vector<std::vector<w>> &vDist, std::vector<std::vector<int>> &vPath)
    {
        FloydWarShall(vDist, vPath);

        for (int i = 0; i < _verPoint.size(); i++)
        {
            _PrintShortLine(_verPoint[i], vDist[i], vPath[i]);
            std::cout << "\n";
        }
    }
};